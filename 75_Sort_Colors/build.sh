#!/bin/bash

set -x
bear -- clang++ -Wall -Wextra -D_GLIBCXX_DEBUG -O0 -ggdb -fsanitize=address -fno-omit-frame-pointer -I../shared/cpp/ ../shared/cpp/readfile.cpp main.cpp -o exec
