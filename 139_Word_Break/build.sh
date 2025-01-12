#!/bin/bash

set -x
clang++ -Wall -Wextra -D_GLIBCXX_DEBUG -O0 -ggdb -fsanitize=address -fno-omit-frame-pointer main.cpp -o exec
