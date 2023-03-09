# Parallel Matrix Operations
This program performs parallel matrix operations using OpenMP. The program constructs a grid of dimensions ROWS x COLS and then performs operations on a subgrid of dimensions `subgrid_dimention` x `subgrid_dimention`. The program calculates the maximum value of each row of the subgrid and the sum of all elements in each row.

## Usage
To compile the program, run the following command:
```
gcc -o assignment2 assignment2.c -fopenmp
```
To run the program, use the following command:
```
./assignment2 <subgrid_dimention> <threads>
```
where `<subgrid_dimention>` is the dimension of the subgrid and `<threads>` is the number of threads to use for parallelization.

## Example
```
./assignment2 10 4
```
This command runs the program with a subgrid dimension of 10 and using 4 threads for parallelization.

## Output
The program outputs the total time taken to perform the matrix operations in milliseconds.

## Acknowledgements

This project was completed as part of a course on parallel computing at Harokopio University.
