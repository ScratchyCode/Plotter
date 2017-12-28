#!/bin/bash
DIR=$(dirname "$0")
cd $DIR

./plotter.out
gnuplot -e "plot 'grafico.dat'" -p
rm graph.dat

exit
