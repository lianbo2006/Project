#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import math
print('坐标计算')
def move(x, y, step, angle=0):
    nx = x + step * math.cos(angle)
    ny = y - step * math.sin(angle)
    return nx, ny
x=float(input('请输入横坐标：'))
y=float(input('请输入纵坐标：'))
d=float(input('请输入位移：'))
r=float(input('请输入角度：'))/180*math.pi
x1,y1=move(x,y,d,r)
print('新坐标为:%0.01f,%0.01f' %(x1,y1))
print('解一元二次方程')
def quadratic(a, b, c):
    deta=b*b-4*a*c
    if a==0 and b!=0 and c!=0:
        x1=-c/b
        return "x=%0.1f" %(x1)
    elif a==0 and b==0:
        return "x为任意值"
    elif a==0 and b!=0 and c==0:
        return "x为任意值"
    elif deta<0:
        return "x=0"
    elif deta==0:
        x1=-b/2*a
        return "x1=x2=%0.1f" %(x1)
    else:
        x1=(-b+math.sqrt(b*b-4*a*c))/(2*a)
        x2=(-b-math.sqrt(b*b-4*a*c))/(2*a)
        return "x1=%0.1f,x2=%0.1f" %(x1,x2)
a=float(input('请输入a：'))
b=float(input('请输入b：'))
c=float(input('请输入c：'))
print(quadratic(a, b, c))
