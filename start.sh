#!/bin/bash
DIR=$(dirname "$0")
cd $DIR

./plotter.out
gnuplot -e "plot 'graph.dat'" -p
rm graph.dat

exit
