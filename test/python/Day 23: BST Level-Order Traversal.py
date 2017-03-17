#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root
    def levelOrder(self,root):
        #Write your code here
        queue=[root]
        while queue:
            root=queue.pop()
            print (root.data,end=" ") #在同一行输出，元素间同空格相隔
            if root.left:
                queue.insert(0,root.left)
            if root.right:
                queue.insert(0,root.right)
T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
myTree.levelOrder(root)
