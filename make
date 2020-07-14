#!/bin/bash

echo "compiling..."

gcc pre.c -o pre
gcc sort.c -o sort
gcc pipe.c -o pipe
gcc prog3.c -o prog3

echo "compile finished..."
