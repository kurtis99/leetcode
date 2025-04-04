#!/bin/bash

set -x
bear --  clang++ -Wall -Wextra -D_GLIBCXX_DEBUG -O0 -ggdb -fsanitize=address -fno-omit-frame-pointer -I../shared/cpp/ ../shared/cpp/linked_list.cpp main.cpp -o exec
