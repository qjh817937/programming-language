#!/bin/bash
current_dir=$(cd `dirname $0`; pwd)

function download() 
{
    git clone --depth=1 git://github.com/richhickey/clojure.git
    git clone --depth=1 git://github.com/richhickey/clojure-contrib.git
}

function compile() 
{
    cd $current_dir/clojure
    ant clean jar

    cd $current_dir/clojure-contrib
    mvn package -Dclojure.jar=$current_dir/clojure/clojure-1.2.0-master-SNAPSHOT.jar 
    mvn clojure:repl -Dclojure.jar=$current_dir/clojure/clojure-1.2.0-master-SNAPSHOT.jar 
}

function run1() 
{
    cd $current_dir
    java -jar $current_dir/clojure/clojure-1.2.0-master-SNAPSHOT.jar $current_dir/helloworld.clj
}

function run2() 
{
    cd $current_dir
    java -cp $current_dir/clojure/clojure-1.2.0-master-SNAPSHOT.jar clojure.main $current_dir/helloworld.clj
}

function run3() 
{
    cd $current_dir
    export CLASSPATH=$current_dir/clojure/clojure-1.2.0-master-SNAPSHOT.jar
    ./clojure-contrib/launchers/bash/clj-env-dir  ./helloworld.clj
}

download

compile

run1
run2
run3

# repl: 
#   Usage: java -cp clojure.jar clojure.main [init-opt*] [main-opt] [arg*]
#       With no options or args, runs an interactive Read-Eval-Print Loop
# java -cp ./clojure/clojure-1.2.0-master-SNAPSHOT.jar clojure.main
