#!/usr/bin/python
#coding=utf-8
import sys;
import getopt;

if __name__ == '__main__':
    try:
        opts,args = getopt.getopt(sys.argv[1:], "ht:p:");
    except getopt.GetoptError:
        usage();
        sys.exit(1);

    for opt,value in opts:
        print opt, value;

    print "end";
