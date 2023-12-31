#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>  
using namespace muduo;
using namespace muduo::net;

class ChatServer {
public:
// 初始化聊天服务器对象
    ChatServer(muduo::net::EventLoop *loop,
               const muduo::net::InetAddress &listenAddr,
               const string &nameArg);
               
    // 启动ChatServer服务
    void start();

private:
    // TcpServer绑定的回调函数，当有新连接或连接中断时调用
    void onConnection(const muduo::net::TcpConnectionPtr &con);
    // TcpServer绑定的回调函数，当有读写事件发生时调用
    void onMessage(const muduo::net::TcpConnectionPtr &con,
                   muduo::net::Buffer *buf,
                   muduo::Timestamp time);

private:
    TcpServer _server;
    EventLoop *_loop;
};


#endif