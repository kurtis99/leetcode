#!/bin/bash

set -x
clang  -Wall -Wextra -O0 -ggdb -fsanitize=address -fno-omit-frame-pointer main.c -o exec
