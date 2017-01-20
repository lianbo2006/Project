#!/usr/bin/env python3
# -*- coding: utf-8 -*-
age = input('请输入你的年龄:');
weight = input('请输入你的体重(kg):');
height = input('请输入你的身高(m):');
age = int(age);
weight = float(weight);
height = float(height);
BMI = weight/(height*height);
if age >= 18:
    print('你的年龄是:%d,属于成人' % age)
elif age >= 6:
    print('你的年龄是:%d,属于青年' % age)
else:
    print('你的年龄是:%d,属于儿童' % age)
if BMI > 32:
    print('你的身高是: %.2f米,你的体重是:%.1f千克,BMI为:%.1f,属于严重肥胖' %(height,weight,BMI))
elif BMI >= 28:
    print('你的身高是: %.2f米,你的体重是:%.1fv,BMI为:%.1f,属于肥胖' %(height,weight,BMI))
elif BMI >= 25:
    print('你的身高是: %.2f米,你的体重是:%.1f千克,BMI为:%.1f,属于过重' %(height,weight,BMI))
elif BMI >= 18.5:
    print('你的身高是: %.2f米,你的体重是:%.1f千克,BMI为:%.1f,属于正常' %(height,weight,BMI))
else:
    print('你的身高是: %.2f米,你的体重是:%.1f千克,BMI为:%.1f,属于过轻' %(height,weight,BMI))