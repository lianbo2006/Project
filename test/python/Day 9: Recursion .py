#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def factorial (a) :
	if a==1:
		return 1
	else:
		return a*factorial(a-1)


n = int(input().strip())
print(factorial(n))
