#!/usr/bin/env python3
# -*- coding: utf-8 -*-
print(0xff18,3.14e9);
print('I\'m learning\nPython.');
print('''I\'m learning
Python.''');
print('I\'m\"OK\"!');
print('\\\t\\');
print(r'\\\t\\');
print(3<2,3>2,3<2 and 3>2);
g = 123
f = 456.789
h=9/6;
j=9/3;
k=9//6;
s1 = 'Hello, 中文'
s2 = r'Hello, \'Adam\''
s3 = 'Hello, "Bart"'
s4 = '''Hello,
Lisa!'''
print(g,f,h,j,k);
print(s1);
print(s2);
print(s3);
print(s4);
print( '\u4e2d\u6587');
print(ord('A'));
print(chr(56));
print(s1.encode('utf-8'));
print(b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8'));
print(len("中文"));
