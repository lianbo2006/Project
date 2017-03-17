#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket
import datetime

HOST='0.0.0.0'
PORT=3434

#AF_INET 说明使用IPV4地址，SOCK_STREAM指明TCP
s= socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((HOST,PORT))    #绑定ip与端口
s.listen(1)         #开始TCP监听

while True:
    conn,addr=s.accept()         #接收TCP连接，并返回新的socket对象
    print("Clint %s connected!" % str(addr))#输出客户端ip地址
    dt=datetime.datetime.now()
    message="Current time is " + str(dt)
    conn.send(message.encode('utf-8'))#向客户端发送当前时间
    print('Sent:',message)
    conn.close()#关闭连接
