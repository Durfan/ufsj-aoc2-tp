#!/usr/bin/gnuplot
set term svg enhanced size 800,480

set xrange [1:32]
set yrange [0:100]

set format y "%.0f%%"
set logscale x 2
set grid

set xtics (1,2,4,8,16,32)
set ytics 10

set key autotitle columnheader outside top right

set xlabel "Palavras por Bloco"
set ylabel "Cache Hit"

set title "Quick Sort"
set output "./output/quicksort_hit.svg"
plot for [i=0:5] './output/quicksort.dat' u 2:3 index i t columnhead(1) smooth bezier

set title "Selection Sort"
set output "./output/selection_hit.svg"
plot for [i=0:5] './output/selection.dat' u 2:3 index i t columnhead(1) smooth bezier

set title "Bubble Sort"
set output "./output/bubblesort_hit.svg"
plot for [i=0:5] './output/bubblesort.dat' u 2:3 index i t columnhead(1) smooth bezier


set ylabel "Cache Miss"

set title "Quick Sort"
set output "./output/quicksort_miss.svg"
plot for [i=0:5] './output/quicksort.dat' u 2:4 index i t columnhead(1) smooth bezier

set title "Selection Sort"
set output "./output/selection_miss.svg"
plot for [i=0:5] './output/selection.dat' u 2:4 index i t columnhead(1) smooth bezier

set title "Bubble Sort"
set output "./output/bubblesort_miss.svg"
plot for [i=0:5] './output/bubblesort.dat' u 2:4 index i t columnhead(1) smooth bezier

