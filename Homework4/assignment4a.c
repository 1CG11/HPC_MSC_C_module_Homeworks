#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* Function prototypes */
int read_vec_from_file(char const * const filename, double v[const], int const n);
int write_vec_to_file(char const * const filename, double const v[const], int const n);
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

/**
*@brief Function to use the traditional insertion sort algorithm (via shifting) to
*       sort an array from lowest magnitude to highest, working from the 
        first element to the last element.
@param in       Array
@param sorted   Array
@param N        int
*/
void insertion_sort(double const in[const], double sorted[const], int const N)
{
    sorted[0]=in[0];

    for(int i=1; i < N; i++){
       
        int j = i-1;

        double key = in[i];
        
        while(j>=0 && sorted[j] > key){
            
            sorted[j+1]=sorted[j];

            j--;
            
            }
        sorted[j+1]=key;

    }
}

/**
This is the "usual algorithm" but the assignment actually wanted to do it a different way
...but I'm leaving it here anyway.
void insertion_sort(double const in[const], double sorted[const], int const N)
{
    double temp;
    
    for(int i=0; i<N; i++){
        
        sortjed[i]=in[i];
    }
    
    for(int i=1; i<N; i++){
    
        int j = i-1;
        
        double key = sorted[i];

        while(j >= 0 && sorted[j] > key){
            
            sorted[j+1] = sorted[j];

            j--; 
        }
        
        sorted[j+1] = key;
}
*/


/**
*@brief    Function to sort an array from lowest magnitude to highest using the
           Bubble sort algorithm, working from the last element to the first
           element of the array.
*@param arr Pointer    Pointer to the array to be sorted
*@param N   int        Size of array
*/
void bubblesort(double * const arr, int const N)
{
    
    bool swap_detected;

    for(int i = N-1; i > 0; i--){
        
        swap_detected = false;

        for(int j=N-1; j>0; j--){


            if( arr[j] < arr[j-1] ){
    
                double temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swap_detected = true; 
            }
        }
        if(!swap_detected){
            break;
        }
    }
}


/** 
*@brief    Function to sort an array from lowest magnitude to highest using the
           Bubble sort algorithm, working from the last element to the first
           element of the array using recursion.
*@param arr Pointer    Pointer to the array to be sorted
*@param N   int        Size of array
void bubblesort_recursive(double * const arr, int const N)
{
    //Base case check 
    if(N==1){
        return;
    }
    
    //Swap counts
    int count = 0;

    for(int i = N-1; i > 0; i--){
        
        if( arr[i] < arr[i-1]){
            double temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            count++;
        }
    }

    if(count == 0){
        return;
    }

    bubblesort_recursive(arr,N-1);
}
*/

/**
*@brief Function to read a file called "data.txt" and print n doubles to the array v (of size n)
*@param filename Pointer
*@param v[]      Array
*@param n        int
*@return 0 upon succes, -1 otherwise
*@author Cillian Grall
*/
int read_vec_from_file(const char * filename, double v[], const int n)
{
    FILE *fp = NULL;   /*Null pointer for error checking input file*/
    
    /*if statement to check that the input file exists*/
    if((fp = fopen(filename,"r")) == NULL){
       
        char errmsg[128]; 

        sprintf(errmsg, "Error reading from %s on line %d in file %s",\
       
                filename, __LINE__, __FILE__); 
        
        perror(errmsg);
       
        return -1;
    }
    
    /*For loop to add doubles from input file to entries/components of array v*/
    for( int i = 0; i<n; i++){
        
        /*if statement to check that every entry of v gets assigned a double from inputfile*/
        if((fscanf(fp, "%lf" , v+i ) != 1)){    /* (v+i) == &v[i] == &(v[i]) */
           
            char errmsg[256];
            
            sprintf(errmsg, "Error reading from %s on line %d in file %s",\
                    
                    filename, __LINE__,__FILE__);

            perror(errmsg);
            
            fclose(fp);

            return -1;

        }
    
    }
    
    fclose(fp);
    
    return 0;
}

/**
*@brief Function to write an array of n elements to a file
*@param filename Pointer
*@param v[]      Array
*@param n        Int
*@return 0 upon success, -1 otherwise.
*/
int write_vec_to_file( const char * filename, const double v[], const int n)
{   
    
    FILE * fo = NULL;

    if((fo = fopen(filename,"w")) == NULL){
        
        char errmsg[128]; 

        sprintf(errmsg, "Error writing to %s on line %d in file %s", filename, __LINE__, __FILE__); 
        
        perror(errmsg);
       
        return -1;

    }

    for( int i = 0; i<n; i++){
        
        if((fprintf(fo, "%lf " , v[i] ) < 0)){    /* (v+i) == &v[i] == &(v[i]) */
            
            char errmsg[256];
            
            sprintf(errmsg, "Error writing from %s on line %d in file %s",\
                    
                    filename, __LINE__,__FILE__);

            perror(errmsg);
            
            fclose(fo);

            return -1;

        }

    }
    
    fclose(fo);

    return 0;
}
