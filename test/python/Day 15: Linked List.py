#!/usr/bin/env python3
# -*- coding: utf-8 -*-
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
class Solution:
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next
     def insert(self,head,data):
        #Complete this method

        # current = head
        #
        # if (current == None):
        #     return Node(data)
        #
        # while current:
        #     if (current.next == None):
        #         current.next = Node(data)
        #         break
        #     else:
        #         current = current.next
        #
        # return head
        current=head
        if (current==None):
            return Node(data)
        while current:
            if(current.next==None):
                current.next=Node(data)
                break
            else:
                current=current.next
        return head

mylist = Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head,data)
mylist.display(head);
