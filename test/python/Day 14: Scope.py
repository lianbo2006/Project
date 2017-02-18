#!/usr/bin/env python3
# -*- coding: utf-8 -*-
class Difference:
    def __init__(self, a):
        self.__elements = a
	# Add your code here
        self.maximumDifference=0
    def computeDifference(self):
        for x in range(0,int(_)):
            for y in range(x,int(_)):
                dd=abs(__elements[x]-__elements[y])
                if dd>self.maximumDifference:
                    self.maximumDifference=dd
# End of Difference class

_ = input()
a = [int(e) for e in input().split(' ')]

d = Difference(a)
d.computeDifference()

print(d.maximumDifference)