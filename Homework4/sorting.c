#include <stdbool.h>


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
