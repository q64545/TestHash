#!/usr/bin/env bash
g++ -std=c++11 -shared main.cc basic_hash.cc -o unit_test.so -O2
g++ unit_test.so -o unit_test
