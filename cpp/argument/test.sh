#!/bin/bash

g++ gendata.cpp -o gendata
./gendata 150000 > data

arg=`cat data`
g++ test.cpp -o test
./test $arg > test.out
