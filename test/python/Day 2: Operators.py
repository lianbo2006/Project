#!/usr/bin/env python3
# -*- coding: utf-8 -*-
meal_cost=float(input())
tip_percent=int(input())
tax_percent=int(input())
tip=meal_cost*(tip_percent/100)
tax=meal_cost*(tax_percent/100)
total_cost=round(meal_cost+tip+tax)
print('The total meal cost is %d dollars.' %total_cost)
