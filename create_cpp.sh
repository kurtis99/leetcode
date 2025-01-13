#!/bin/bash

TGT_DIR=$(echo $1 | tr " " "_" | tr -d ".")

mkdir $TGT_DIR
cp -r ./skeleton/cpp/* $TGT_DIR
cp -r ./skeleton/cpp/.gdbinit $TGT_DIR
cp -r ./skeleton/cpp/.lvimrc  $TGT_DIR
