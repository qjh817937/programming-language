#!/usr/bin/python
#coding=utf-8

import ConfigParser;

config_file=["conf", "conf2"]
config = ConfigParser.ConfigParser();
config.read(config_file);
config.set("main", "key4", "x444444444444x");
for sectionName in config.sections():
    for item in config.items(sectionName):
        key = item[0]
        val = item[1]
        print "key=%s,value=%s" % (key,val)

