#include <ServerManager.hpp>
#include <fstream>

const std::map<std::string, availableCommands>  ServerManager::cmdStoI =
{
    {"help", HELP},
    {"start", START},
    {"restart", RESTART},
    {"stop", STOP},
    {"showusers", SHOWUSERS},
    {"kick", KICK},
    {"messageto", MESSAGETO},
    {"messageall", MESSAGEALL},
    {"exit", EXIT}
};

const std::vector<std::string> ServerManager::helpEpressions =
{
    "start - start the server ",
    "restart - restart the server ",
    "stop - stop work of the server ",
    "showusers - list of online users ",
    "kick userName(arg1) - kick user(arg1), if one is online ",
    "messageto userName(arg1) message(arg2) - send a user(arg1) a message(arg2) ",
    "messageall message(arg1) - send all users a message(arg1) ",
    "exit - stop server and stop the terminal execution"
};

std::map<std::string, std::string> ServerManager::cfgInit =
{
    {"ip", ""},
    {"connectionPort", ""},
    {"maxUsers", ""}
};


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
//    case EXIT:
//        exit();
//        break;
    default:
        std::cout << "Command \"" << cmd << "\" doesn't exist. Try \"help\" " << std::endl;
    }
}

bool ServerManager::checkCfg(const std::string &filePath = "/home/left/gitProjects/Server/src/SocketServerComponent/src/cfg/settings.cfg")
{
    std::ifstream cfgFile;
    cfgFile.open(filePath);
    if(!cfgFile.is_open())
    {
        std::cout << "Config file has not founded!";
        return false;
    }

    std::string buffer;
    while(getline(cfgFile, buffer))
    {
        auto div = buffer.find("=");
        auto field = buffer.substr(0, div);
        auto fieldPos = cfgInit.find(field);

        if(fieldPos == cfgInit.end())
        {
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

    mHostSocket = std::make_shared<TcpSocket>(cfgInit.find("ip")->second, cfgInit.find("connectionPort")->second);
    mHostSocket->listen(std::stoi(cfgInit.find("maxUsers")->second));

    mListener = std::make_shared<ConnectionHandler>(mHostSocket);
    //mMessanger = std::make_shared<MessageHandler>(mListener->getOnlineUsers());

    waitConnection = std::thread([this](){
        mListener->acceptConnection();
    });
    waitConnection.detach();

//    messangeThread = std::thread([this](){
//        mMessanger->checkForMessage();
//    });
//    messangeThread.detach();
}

//void ServerManager::restart()
//{
//    stop();
//    start();
//}

void ServerManager::exit()
{
    close(mHostSocket->getSocketfd());
    exit();
}
