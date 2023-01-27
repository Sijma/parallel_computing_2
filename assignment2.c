#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

#define ROWS 320
#define COLS 760

void construct_grid(int rows, int cols, unsigned int*** grid) {
    unsigned int count = 0;
    *grid = (unsigned int**)calloc(rows, sizeof(unsigned int*));
    for (unsigned int i = 0; i < rows; i++) {
        (*grid)[i] = (unsigned int*)calloc(cols, sizeof(unsigned int));
        for (unsigned int j = 0; j < cols; j++) {
            (*grid)[i][j] = count;
            count++;
        }
    }
}

int main(int argc, char* argv[]) {
	if(argc != 2){
		printf("Please provide only a single argument, for the size of the subgrid.\n");
	}

	char *a = argv[1];
	int subgrid_dimention = atoi(a);
	
    unsigned int new_row = ROWS * COLS;
    unsigned int new_col = subgrid_dimention * subgrid_dimention;

    unsigned int** grid;
    construct_grid(new_row, new_col, &grid);

    double start_time = omp_get_wtime() * 1000;
    #pragma omp parallel for
    for (unsigned int i = 0; i < new_row; i++) {
        unsigned int max_value = grid[i][0];
        unsigned int sum = 0;
        for (unsigned int j = 0; j < new_col; j++) {
            sum += grid[i][j];
            if (grid[i][j] > max_value) {
                max_value = grid[i][j];
            }
        }
    }
    double end_time = omp_get_wtime()* 1000;
    printf("%f\n", end_time - start_time);

    return 0;
}
