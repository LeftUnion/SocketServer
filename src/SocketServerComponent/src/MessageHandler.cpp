//#include <MessageHandler.hpp>

//MessageHandler::MessageHandler(const std::shared_ptr<std::list<User>> monlineUsers, int somefd)
//{
//    onlineUsers = monlineUsers;
//    this->pofd = somefd;
//}

//void MessageHandler::resendMessages()
//{
//    while (!messages.empty())
//    {
//        for(auto &it : *onlineUsers)
//        {
//            if(it.login != messages.front().first.login)
//                send(it.socketDS, messages.front().second.c_str(), sizeof (messages.front().second.c_str()), 0);
//        }
//        messages.pop();
//        buffer = "";
//    }
//}

//void MessageHandler::checkForMessage()
//{
//    while (true) {
//        int ret = epoll_wait(pofd, events, 20, 1000);
//        for(int i = 0; i < ret; i++)
//        {
//            std::cout << events[i].events;
//        }

//        for(auto it : *onlineUsers)
//        {
//            int bytesRead = recv(it.socketDS, buffer, sizeof(buffer), MSG_DONTWAIT);
//            if(bytesRead > 0)
//                messages.push(msgSender(it, buffer));

//        }
//        resendMessages();
//    }
//}
