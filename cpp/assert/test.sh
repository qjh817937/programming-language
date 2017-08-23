#!/bin/bash

#编译时可以用：g++  -D NDEBUG   filename.cpp -o filename 来指定宏开关。
#特别注意assert，它仅仅在调试中起作用，在非debug下编译的程序将忽略assert语句。所以，千万不能试图用assert来控制你的程序逻辑。

g++ -D NDEBUG test.cpp
./a.out

echo ""

g++ test.cpp
./a.out
