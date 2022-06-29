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

bool ServerManager::checkCfg(const std::string &filePath = "/home/left/gitProjects/Server/src/SocketServerComponent/src/cfg/settings.cfg")
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
    for(const auto &it : helpEpressions)
        std::cout << it << std::endl;
    std::cout << std::endl;
}

void ServerManager::start()
{
    if(mHostSocket != nullptr){
        std::cout << "Host socket is already created!" << std::endl;
        return;
    }
    checkCfg(); //toDo Check if work

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
        mMessanger->checkForMessage();
    });
    messangeThread.detach();
}

void ServerManager::exit()
{
    close(mHostSocket->getSocketDs());
    exit();
}
