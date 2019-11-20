#!/bin/bash

gcc plotter2.c -lm -O3 -o plotter2.exe
./plotter2.exe

echo "Plotting..."
gnuplot script.gp

echo "Done."

exit
