#!/bin/bash
cd $(dirname $0)
java -cp ../../env-setup/clojure/clojure-1.2.0-master-SNAPSHOT.jar clojure.main structmaps.clj 
