#include <stdio.h>
#include <stdlib.h>

#include "file_io.h"
#include "sorting.h"



/* Function prototypes */
void print_array_doubles(double const A[const], int const N);
void insertion_sort(double const in[const], double sorted[const], int const N);
void bubblesort(double * const arr, int const N);


int main(void)
{
	int N;

	/*Prompt user to enter a value for N. Read in and store.*/
    printf("Please type  number into the terminal: \n");

    /*Creating a buffer to store the intput from terminal for safety check*/
    char buffer[100];
   
    /*Assigning storage and filling the buffer from stdin*/
    fgets(buffer, sizeof(buffer), stdin);

    /*Reading from buffer and checking if it was read correctly*/
    if (sscanf(buffer, "%d", &N) == 1) {
        printf("You entered: %d\n", N);
    }   
    else {
         printf("Invalid input!\n");
    }



	/*Allocate memory for two arrays to hold N doubles each.*/
	
	double *numbers = malloc(N * sizeof(double));
	double *sorted_numbers = malloc(N * sizeof(double));    

	/*Populate "numbers" array from "numbers.txt"*/ 
	/* 	by calling read_vec_from_file function*/
        
    const char * input_file = "numbers.txt";
    
    read_vec_from_file(input_file, numbers, N);
    if (read_vec_from_file(input_file, numbers, N) != 0) {
        fprintf(stderr, "Failed to read numbers from %s. Exiting program.\n", input_file);
        free(numbers);
        free(sorted_numbers);
        return 1;  // Exit main with non-zero code to indicate error
    }

	printf("Original Numbers:\t");
	print_array_doubles(numbers, N);
	printf("\n\nSorting......\n\n");
	insertion_sort(numbers, sorted_numbers, N);
	printf("Sorted Numbers:  \t");
	print_array_doubles(sorted_numbers, N);

	/* Call function write_vec_to_file to write the
	*  sorted array to "sorted.txt"
    */
    write_vec_to_file("data.txt",sorted_numbers,N);

	printf("\n\n\n-----------Bubblesort----------\n");
	printf("Original Numbers:\t");
	print_array_doubles(numbers, N);
	printf("\n\nSorting......\n\n");
	bubblesort(numbers,N);
	printf("Sorted Numbers:  \t");
	print_array_doubles(numbers, N);
	printf("\n");
    
    free(numbers);
    free(sorted_numbers);
	return 0;
}

/**
*@brief    Function to print the elements of an array of length N 
*@param    A    Array
*@param    N    Int
*/
void print_array_doubles(double const A[const], int const N)
{
    printf("[");
    for(int i=0; i<N; i++){
        printf("%f",A[i]);
        
        if(i<N-1){
            printf(" ,");
        }
    }
    printf("]\n"); 
}

