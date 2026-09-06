#!/bin/bash

clear

rm *.class -f

javac Main.java ; /usr/lib/jvm/java-15-openjdk-15.0.1.9-2.rolling.fc32.x86_64/bin/java --enable-preview -XX:+ShowCodeDetailsInExceptionMessages -Dfile.encoding=UTF-8  Main
