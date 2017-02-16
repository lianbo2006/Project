#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#number of entries in phonebook
n = int(input().strip())
phoneBook = {}

#assign in phoneBook
for i in range(n):
    name, num = input().strip().split()
    phoneBook[name] = num

#query phoneBook while there is input, exit when EOF
qName = input().strip()
while(qName):
    if qName in phoneBook:
        print('%s=%s' %(qName,phoneBook[qName]))
    else:
        print('Not found')
    qName = input().strip()

# while(True):
#     try:
#         qName = input().strip()
#         if qName in phoneBook:
#             print('%s=%s' %(qName,phoneBook[qName]))
#         else:
#             print('Not found')
#     except EOFError:
#         break