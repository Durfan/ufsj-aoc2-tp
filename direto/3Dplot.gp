#!/usr/bin/gnuplot

set term svg enhanced size 1024,640

set xlabel "Tamanho da Cache"
set xrange [544:0]

set ylabel "Palavra por Bloco"
set yrange [0:33]

set format z "%.0f%%"
set autoscale z

set xtics (16,32,64,128,256,512)
set ytics (1,2,4,8,16,32)

set ticslevel 0

unset key
set grid ztics
set hidden3d

set title "Quick Sort - Cache Hit"
set output "./output/3Dquicksort_hit.svg"
splot for [i=0:5] './output/quicksort.dat' u 1:2:3 index i t columnhead(1) w lines
