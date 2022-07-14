#ifndef USER_HPP
#define USER_HPP

#include <TcpSocket.hpp>
#include <BaseMessage.hpp>

#include <memory>
#include <queue>

class User
{
private:
    static size_t userCount;
    std::shared_ptr<BaseSocket> mReadSocket = nullptr;
    std::shared_ptr<BaseSocket> mWriteSocket = nullptr;
    //std::queue<BaseMessage> messageHistory; TODO IN DB
    std::string userName;

public:
    User() = default;
    User(int socketfd, sockaddr_in addr);
    ~User() = default;

    std::shared_ptr<BaseSocket> getReadSocket() const;
    std::shared_ptr<BaseSocket> getWriteSocket() const;
    void setReadSocket(std::shared_ptr<BaseSocket>);

};



#endif // USER_HPP
