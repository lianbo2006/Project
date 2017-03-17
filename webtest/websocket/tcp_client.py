#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket

HOST='123.206.22.180'
PORT=3434

#AF_INET 说明使用IPV4地址，SOCK_STREAM指明TCP
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)



s.connect((HOST,PORT))
print('Connet %s:%d OK' %(HOST,PORT))
data=s.recv(1024)     #接收数据，本次接受的数据最大长度为1024
print('Received :',data.decode('utf-8'))
s.close()             #关闭连接
