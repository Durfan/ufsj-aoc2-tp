#!/usr/bin/gnuplot

set term svg

set xlabel "Palavras por Bloco"
set xrange [0:33]
set autoscale y

set xtics ("1" 1, "2" 2, "4" 4, "8" 8, "16" 16, "32" 32)
set grid ytics lc rgb "#bbbbbb" lw 1 lt 0
set grid xtics lc rgb "#bbbbbb" lw 1 lt 0


set ylabel "Cache Hit %"

set title "Quick Sort - Cache Hit"
set key autotitle columnheader bottom right
set output "./output/quicksort_hit.svg"
plot for [i=0:5] './output/quicksort.dat' u 1:2 index i t columnhead(1) smooth bezier

set title "Selection Sort - Cache Hit"
set key autotitle columnheader bottom left
set output "./output/selection_hit.svg"
plot for [i=0:5] './output/selection.dat' u 1:2 index i t columnhead(1) smooth bezier

set title "Bubble Sort - Cache Hit"
set key autotitle columnheader bottom right
set output "./output/bubblesort_hit.svg"
plot for [i=0:5] './output/bubblesort.dat' u 1:2 index i t columnhead(1) smooth bezier


set ylabel "Cache Miss %"

set title "Quick Sort - Cache Miss"
set key autotitle columnheader top right
set output "./output/quicksort_miss.svg"
plot for [i=0:5] './output/quicksort.dat' u 1:3 index i t columnhead(1) smooth bezier

set title "Selection Sort - Cache Miss"
set key autotitle columnheader top left
set output "./output/selection_miss.svg"
plot for [i=0:5] './output/selection.dat' u 1:3 index i t columnhead(1) smooth bezier

set title "Bubble Sort - Cache Miss"
set key autotitle columnheader top right
set output "./output/bubblesort_miss.svg"
plot for [i=0:5] './output/bubblesort.dat' u 1:3 index i t columnhead(1) smooth bezier
