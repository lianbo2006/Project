#!/usr/bin/env python3
# -*- coding: utf-8 -*-
print('请利用循环依次对list中的每个名字打印出Hello, xxx!：')
L = ['Bart', 'Lisa', 'Adam']
for name in L:
    print(name)
print('计算1-10的整数之和：')
sum = 0
for x in range(101):
    sum = sum + x
print(sum)
print('计算1x3x5x...x99:')
acc = 1
n = 0
while n <= 99:
    n = n + 1
    if n%2==0:
        continue
    acc = acc * n
print(acc)
print('set交集、并集')
s1 = set([1, 2, 3])
s2 = set([2, 3, 4])
print('交集:',s1 & s2)
print('并集:',s1 | s2)
print('再议不可变对象')
a=['c', 'b', 'a']
a.sort()
print(a)
c='abc'
d = c.replace('a', 'A')
print('%s\n%s' %(c,d))