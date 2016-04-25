#!/bin/python
#coding=utf-8

import sys

## 
def test_get():
    print "----------", sys._getframe().f_code.co_name , "---------" ## 打印函数名

    d={"k":"v"}
    print d
    print d.get("k")
    print d.get("k1")  ## 找不到则为None
    print d.get("k1", "v1") ## 默认值,找不到则使用默认值
test_get()

## 获取dict中的所有key
def test_keys():
    print "----------", sys._getframe().f_code.co_name , "---------" ## 打印函数名

    d={"k1":"v1", "k2":"v2" }
    print d.keys()  

test_keys()

## dict中的value 可以是一个函数
def test_value_is_fun():
    print "----------", sys._getframe().f_code.co_name , "---------" ## 打印函数名
    def fun():
        print "fun";

    fun()
    d={"fun": fun}
    print d 

    d["fun"]()
test_value_is_fun()
