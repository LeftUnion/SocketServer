#include <ServerManager.hpp>
#include <fstream>

void ServerManager::exec(const std::string &&cmd)
{
    availableCommands chooseCmd;
    auto it = cmdStoI.find(cmd);
    if(it != cmdStoI.end())
        chooseCmd = it->second;
    switch (chooseCmd)
    {
    case HELP:
        help();
        break;
    case START:
        start();
        break;
//    case RESTART:
//        restart();
//        break;
//    case STOP:
//        stop();
//        break;
//    case SHOWUSERS:
//        showusers();
//        break;
//    case KICK:
//        kick();
//        break;
//    case MESSAGETO:
//        //messageto(arg);
//        break;
//    case MESSAGEALL:
//        messageall();
//        break;
    case EXIT:
        exit();
        break;
    default:
        std::cout << "Command \"" << cmd << "\" doesn't exist. Try \"help\" " << std::endl;
    }
}

bool ServerManager::checkCfg(const std::string &filePath)
{
    std::ifstream cfgFile;
    cfgFile.open(filePath);
    if(!cfgFile.is_open()){
        std::cout << "Config file has not founded!";
        return false;
    }

    std::string buffer;
    while(getline(cfgFile, buffer)) {
        auto div = buffer.find("=");
        auto field = buffer.substr(0, div);
        auto fieldPos = cfgInit.find(field);
        if(fieldPos == cfgInit.end()){
            std::cout << "We can not find field: " << field << std::endl;
            return false;
        }
        fieldPos->second = buffer.substr(div + 1, buffer.size() - 1);
    }

    return true;
}

void ServerManager::help() const
{
    std::cout << "start - start the server" << std::endl;
    std::cout << "restart - restart the server" << std::endl;
    std::cout << "stop - stop work of the server" << std::endl;
    std::cout << "showusers - list of online users" << std::endl;
    std::cout << "kick userName(arg1) - kick user(arg1), if one is online " << std::endl;
    std::cout << "messageto userName(arg1) message(arg2) - send a user(arg1) a message(arg2)" << std::endl;
    std::cout << "messageall message(arg1) - send all users a message(arg1) " << std::endl;
    std::cout << "exit - stop server and stop the terminal execution" << std::endl;
}

void ServerManager::start()
{
    if(mHostSocket != nullptr){
        std::cout << "Host socket is already created!" << std::endl;
        return;
    }
    checkCfg("/home/left/gitProjects/Server/src/SocketServerComponent/src/cfg/settings.cfg"); //toDo Check if work

//    Спросить у Дениса
//    int maxUsers = std::stoi(cfgInit.find("maxUsers")->second);
//    std::string inIP = cfgInit.find("ip")->second;
//    std::string inPort = cfgInit.find("port")->second;
//    mHostSocket = std::make_shared<Socket>(inIP, inPort);

    mHostSocket = std::make_shared<Socket>(cfgInit.find("ip")->second, cfgInit.find("port")->second);
    mHostSocket->listenAddr(std::stoi(cfgInit.find("maxUsers")->second));

    mListener = std::make_shared<ConnectionHandler>(mHostSocket);
    mMessanger = std::make_shared<MessageHandler>(mListener->getOnlineUsers(), mListener->polfd());

    waitConnection = std::thread([this](){
        mListener->userAuth();
    });
    waitConnection.detach();

    messangeThread = std::thread([this](){
        while (true) {
            mMessanger->checkForMessage();
        }
    });
    messangeThread.detach();
}

void ServerManager::exit()
{
    close(mHostSocket->getSocketDs());
    exit();
}
