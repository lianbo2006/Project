#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#这是一个计算成绩上升水平的程序
s1=input('please enter first score:');
s2=input('please enter second score:');
r=(int(s2)-int(s1))*100/int(s1);
print('growth rate: %.1f %%' % r);