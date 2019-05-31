#include "main.h"

void plot() {
	printf("teste");
	FILE *pipe = popen("gnuplot -persist", "w");

    if ( pipe == NULL ) {
        printf(" Erro ao abrir pipe para o GNU plot.\n");
        exit(0);
    }

    fprintf(pipe, "plot 'plot_data.txt' w lp\n");
    
	fflush(pipe);
    pclose(pipe);
}