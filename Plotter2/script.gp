set autoscale x
set autoscale y
set autoscale z
set xlabel 'x'
set ylabel 'y'
set zlabel 'z'
set title 'plot'

set terminal png size 1920,1080
set output 'plot.png'

splot 'graph.dat' u 1:2:3 w d
