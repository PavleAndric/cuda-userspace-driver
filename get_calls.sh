#!/bin/bash 
clang main.c -o main 
clang -shared -fPIC -g -o intercept.so intercept.c -ldl
LD_PRELOAD=./intercept.so ./cu
#objdump -T --demangle intercept.so