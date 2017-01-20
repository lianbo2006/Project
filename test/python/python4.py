#!/usr/bin/env python3
# -*- coding: utf-8 -*-
classmates = ['Michael', 'Bob', 'Tracy'];
print(classmates[len(classmates) - 1]);
classmates.append('lyb');
print(classmates);
classmates.pop(1);
print(classmates);
classmates.insert(1, 'Jack')
print(classmates);
classmates[1] = 'Sarah'
print(classmates);
s = ['python', 'java', ['asp', 'php'], 'scheme'];
print(len(s));
t = ('a', 'b', ['A', 'B']);
print(t);
t[2][0] = 'X';
t[2][1] = 'Y';
print(t);
#下面是练习测试
print('下面是练习测试:')
L = [
    ['Apple', 'Google', 'Microsoft'],
    ['Java', 'Python', 'Ruby', 'PHP'],
    ['Adam', 'Bart', 'Lisa']
];
# 打印Apple:
print(L[0][0])
# 打印Python:
print(L[1][1])
# 打印Lisa:
print(L[2][2]);