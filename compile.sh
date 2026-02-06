#!/usr/bin/env bash
gcc_path="/mnt/c/Users/dwlar/mingw64/bin/gcc.exe"
$gcc_path main.c -o pongo.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
echo "sucessfull compilation - hehehe"