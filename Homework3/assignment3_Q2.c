/**
*@brief Defining a function to pull data from a file and place data into an array and defining a function 
*       to take entries from an array and print them to an output file
*@author Cillian Grall
*/

#include <stdio.h>
#include <math.h>

/*Declaring New Prototypes*/
int read_vec_from_file(const char * filename, double v[], const int n);
int write_vec_to_file( const char * filename, const double v[], const int n);


/*Declaring Prototypes from Q1*/
void print_vec(const double v[], const int n);
double dot_prod(const double X[], const double Y[], const int n);
double length(const double v[], const int n);
double L1_norm(const double v[], const int n);
double vector_max_norm(const double v[], const int n);
void cross_product(const double u[], const double v[], double w[]);
void normalise(const double v[], double normalised[], const int n);
double angle_between_vecs(const double u[], const double v[], const int n);

int main(void)
{
    const char * input_file_x = "x_data.txt";
    const char * input_file_y = "y_data.txt";
    const char * output_file = "output_data.txt";
    
    const int n = 3;

    double x[n] = {};

    double y[n] = {};

    read_vec_from_file( input_file_x, x, n );
    read_vec_from_file( input_file_y, y, n );

    /*Print vectors*/
    printf("x = ");
    print_vec(x,n);

    printf("y = ");
    print_vec(y,n);

    /*Print the dot product of x & y*/
    double dotprod = dot_prod(x,y,n);
    printf("DotProd x.y:  %lf \n",dotprod);
    
    /*Print the lengths of vectors x & y*/
    double euclid_length_x = length(x,n);
    double euclid_length_y = length(y,n);

    printf("Length x: %lf \n", euclid_length_x);
    printf("Length y: %lf \n", euclid_length_y);


    /*Print the L1 norm of x & y*/
    double L1norm_x = L1_norm(x,n);
    double L1norm_y = L1_norm(y,n);
   
    printf("L1 norm x: %lf \n", L1norm_x);
    printf("L1 norm y: %lf \n", L1norm_y);

    /*Print the max component of the vectors x & y*/
    double maxnorm_x = vector_max_norm(x,n);
    double maxnorm_y = vector_max_norm(y,n);

    printf("Vector max x: %lf \n",maxnorm_x);
    printf("Vector max y: %lf \n", maxnorm_y);

    /*Print the cross product of x & y*/
    double w[n] = {};
    cross_product(x,y,w); 
    printf("Cross prod xy = ");
    print_vec(w,n);

    /*Print the unit vectors of x & y*/
    double normalised_x[n] = {};
    double normalised_y[n] = {};    
    
    normalise(x,normalised_x, n);
    normalise(y,normalised_y, n);
     
    /*Print the angle between x & y*/
    double angle_between_x_y = angle_between_vecs(x,y,n);
   
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
*@brief Function to print the elements of an Array of size 'n'
*@param v[] Array 
*@param n Size of array v[]
*/
void print_vec(const double v[], const int n)
{

    for( int i=0; i<n; i++){

        if(i == 0){

            printf("{%.2lf, ",v[i]); 
        }

        if(0< i && i <n-1){
            printf("%.2lf, ", v[i]);
        }
            
        if(i == n-1){

            printf("%.2lf}\n",v[i]);
        } 
    }
}

/**
*@brief Function to compute the dot product between two vectors of length 'n'
*@param X[] Array 1 (Vector 1)
*@param Y[] Array 2 (Vector 2)
*@param n   length of vectors
*/
double dot_prod(const double X[], const double Y[], const int n)
{
    double dotprod = 0; /*Used for the summation of the element-wise product of arrays*/

    for(int i=0; i<n; i++){  /*For loop for computing the dot product between the arrays*/
      
      dotprod += X[i]*Y[i];
    
    }

    return dotprod;
}

/**
*@brief Function to compute the (Euclidean) length of a vector  of length 'n'
*@param v[] Array (Vector)
*@param n   length of vector
*/
double length(const double v[], const int n)
{
    double euclid_length = sqrt(dot_prod(v,v,n));  /*Calling dotprod to compute the dot product between v and itself*/

    return euclid_length;
}

/**
*@brief Function to compute the L^1 norm of a vector of length 'n'
*param v[] Array (vector)
*param n   length of vector
*/
double L1_norm(const double v[], const int n)
{
   
    double L1norm = 0; /*Used for the summation of the L^1 norm*/

    for (int i=0; i<n; i++){
    
        L1norm += fabs(v[i]);
    
    }
    
    return L1norm;
}

/**
*brief Function to compute the vector max norm of a vector of length 'n'
* i.e. Compute the L^infinity norm of a vector
*@param v[] Array (vector)
*@param n   Length of Array (vector0
*/
double vector_max_norm(const double v[], const int n)
{ 
    double maxnorm = 0; /*Definition of maxnorm to be updated to store the actual max abs of a vectors entries*/
    
    for(int i=0; i<n; i++){  /*For loop for updating maxnorm*/

        if(maxnorm < fabs(v[i])) maxnorm = fabs(v[i]);
       
    }
    
    return maxnorm;
}

/**
*@brief Function for calculating the cross product of two 3-dim vectors 
*@param u[] Array 1 (vector 1)
*@param v[] Array 2 (vector 2)
*@param w[] Array 3 (vector 3, result of uxv)
*/
void cross_product(const double u[], const double v[], double w[])
{   
        /*Defining the entries of w[] explicitly in terms of entries in u[] and v[]*/
        /*Note:We could juse as well have used a for loop with indices i+1 mod 3 & i+3 mod 3,
        * but this is (slightly) faster. */
        w[0] = (u[1] * v[2]) - (v[1] * u[2]);
        w[1] = - (u[0] * v[2]) + (v[0] * u[2]) ;
        w[2] = (u[0] * v[1]) - (v[0] * u[1]);
  
}

/**
*@brief Function for normalising a vector v of length 'n'
*@param v[]         Array (vector)
*@param normalised  Array (vector)
*@param n           int
*/
void normalise(const double v[], double normalised[], const int n)
{
    double norm_const = 1.0 / length(v,n);  /*Calculating the normalisation constant and storing it*/

    for(int i=0; i<n; i++){   /*For loop for normalising each component of the vector v*/
    
        normalised[i] = v[i] * norm_const;

    }
}

/**
*@brief Function to calculate the angle between two vectors
*@param u[] Array 1 (vector 1)
*@param v[] Array 2 (vector 2)
*@param n   int
*/
double angle_between_vecs(const double u[], const double v[], const int n)
{

    double theta = acos( dot_prod(u,v,n) /( length(u,n) * length(v,n) ) );
    
    return theta;
}
