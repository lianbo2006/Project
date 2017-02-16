#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys


n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip()]
print(*reversed(arr))