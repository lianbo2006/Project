#!/usr/bin/env python3
# -*- coding: utf-8 -*-
f = open(('/home/lianbo2006/Project/test/python/python11.txt'),'w')
for x in range(0,10):
    print (x,end = '',file=f)
print("\n",file=f)
for x in range(0,10):
    print (x,end = ' ',file=f)
f.close()
