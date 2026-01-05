#include <stdio.h>   
#include <stddef.h>  
#include <stdlib.h>  

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
