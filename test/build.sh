#!/bin/bash

set -x
bear -- clang++ -Wall -Wextra -D_GLIBCXX_DEBUG -O0 -ggdb -fsanitize=address -fno-omit-frame-pointer -I../shared/cpp/ ../shared/cpp/heap.cpp heap_test.cpp -o heap_exec
