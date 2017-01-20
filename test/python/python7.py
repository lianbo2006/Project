#!/usr/bin/env python3
# -*- coding: utf-8 -*-
print('绝对值计算')
def my_abs(x):
    if not isinstance(x, (int, float)):
        raise TypeError('错误的输入类型')
    if x >= 0:
        return x
    else:
        return -x
s=input('请输入数字：')
n=int(s)
print(my_abs(n))
print(my_abs(s))