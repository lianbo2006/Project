#!/usr/bin/env python3
# -*- coding: utf-8 -*-
print("利用递归函数移动汉诺塔")
def move(n, a, b, c):
    if n == 1:
        print('move', a, '-->', c)
        return
    move(n-1, a, c, b)
    print('move', a, '-->', c)
    move(n-1, b, a, c)

move(8, 'A', 'B', 'C')