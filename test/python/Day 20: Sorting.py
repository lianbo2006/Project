#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys


n = int(input().strip())
a = [int(a_temp) for a_temp in input().strip().split(' ')]

numOfSwap=0
for i in range(n):
    numSwap  = 0
    for j in range(n-1):
        if  (a[j]>a[j+1]):
            a[j],a[j+1]=a[j+1],a[j]
            numSwap=numSwap+1
            numOfSwap=numOfSwap+1
    if numSwap==0:
        break
print('Array is sorted in',numOfSwap,'swaps.')
print('First Element:',a[0])
print('Last Element:',a[-1])
