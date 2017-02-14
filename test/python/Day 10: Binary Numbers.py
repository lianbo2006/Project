#!/usr/bin/env python3
# -*- coding: utf-8 -*-
n = int(input().strip())
# b=bin(n)[2:]
# consecutive=b.split('0')
# max=1
# for c in consecutive:
# 	if len(c)>max:
# 		max=len(c)
# print(max)
print(max(len(x) for x in bin(n)[2:].split('0')))