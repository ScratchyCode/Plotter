#!/bin/bash
DIR=$(dirname "$0")
cd $DIR
gcc Plotter.c tinyexpr.c -lm -o plotter.out
./plotter.out
gnuplot -e "plot 'graph.dat' with lines" -p

sleep 1
rm graph.dat
rm plotter.out
exit
