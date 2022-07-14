#include <User.hpp>

size_t User::userCount = 0;

User::User(int socketfd, sockaddr_in addr)
{
    mWriteSocket = std::make_shared<TcpSocket>(socketfd, addr);
}

std::shared_ptr<BaseSocket> User::getReadSocket() const
{
    return this->mReadSocket;
}

std::shared_ptr<BaseSocket> User::getWriteSocket() const
{
    return this->mWriteSocket;
}

void User::setReadSocket(std::shared_ptr<BaseSocket> readSocket)
{
    this->mReadSocket = readSocket;
}

