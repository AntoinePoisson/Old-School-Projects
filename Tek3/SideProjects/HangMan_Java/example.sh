#!/bin/bash

rm *.class -f

javac *.java ; /usr/lib/jvm/java-15-openjdk-15.0.1.9-2.rolling.fc32.x86_64/bin/java --enable-preview -XX:+ShowCodeDetailsInExceptionMessages -Dfile.encoding=UTF-8  Example
