#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 3

struct example_struct{
    int class;      /* Class course code */
    double *A;      /* Overall %-age. Pointer to single double */
    char w;         /* 'Y' if passed course, 'N' otherwise */
    int B[DIM];     /* array of marks out of 100 for assignments */
    char q;         /* 'Y' if project complete. 'N' otherwise */
    char *name;     /* Student's name. Pointer to char array */
};


void deep_copy(struct example_struct const *const original, struct example_struct *const copy);
void dump_struct(struct example_struct const  *const);

int main(void)
{
	char const Name[] = "Joe Bloggs";
	struct example_struct orig, cpy, shallow_cpy;

	/*
	 * Populate orig struct 
	 *
	 * NOTE: When you are doing the deep copy, do not 
	 * hardcode the number of charachters and do not 
	 * do character by character copying like I am doing
	 * below for "name". The reason I am doing it this
	 * way below is simply so that I don't give you the
	 * answer. Use the string functions inside the deep_copy
	 * function to figure out how much to allocate and
	 * to also do the copy itself 
	 */
	orig.class 	= 5613;
	orig.A 		= malloc(sizeof *orig.A); 	/* Or sizeof(double) will work 		*/
	if(orig.A == NULL){
		perror("Error allocating memory for orig.A");
		exit(EXIT_FAILURE);
	}
	*orig.A = 0.567;     				/* "*(orig.A)" might be clearer here 	*/

	for (int i = 0; i < DIM; i++) { 		/* Populate array of integers 		*/
		orig.B[i] = rand() % 100; 			
	}

	orig.name = malloc(11);
	if(orig.name == NULL){
		perror("Error allocating memory for orig.name");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 11; i++) { 			/* Copy character array, char by char 	*/
		orig.name[i] = Name[i];
	} 

	orig.q = 'Y';
	orig.w = 'Y';
	/* End of populating original struct */


	/* Deep copy "orig" to "cpy" */
	deep_copy(&orig, &cpy);

	/* print contents of structs to screen */
	printf("Original:\n");
	dump_struct(&orig);
	printf("\nCopy:\n");
	dump_struct(&cpy);
	
	/* Modify some values in the copy */
	*cpy.A 	+= .2;
	cpy.q 	= 'N';
	for (int i = 0; i < DIM; i++) {
		cpy.B[i] -= 10;	
	}

	/* print contents of structs to screen */
	printf("\n------ After Modifications ------\nOriginal:\n");
	dump_struct(&orig);
	printf("\nCopy:\n");
	dump_struct(&cpy);


	/* Shallow copy */
	shallow_cpy = orig;

	/* Modify shallow copy values */
	*shallow_cpy.A 	+= 0.2;
	shallow_cpy.q 	= 'N';
	for (int i = 0; i < DIM; i++) {
		shallow_cpy.B[i] -= 10;	
	}
	/* print contents of structs to screen */
	printf("\n------ Shallow Copy ------\nOriginal:\n");
	dump_struct(&orig);
	printf("\nShallow Copy:\n");
	dump_struct(&shallow_cpy);

	/* Free memory */
	free(orig.A);
	free(orig.name);
	free(cpy.A);
	free(cpy.name);

	return 0;
}

/**
*@brief Function to print the contents of the struct in to stdout
*@param in Pointer 
*/
void dump_struct(struct example_struct const  *const in){
	printf("Name:  %s\n", in->name);
	printf("Class: %d\n", in->class);
	printf("A:     %f\n", *(in->A));
	printf("q:     %c\n", in->q);
	printf("w:     %c\n", in->w);
	printf("B[0]:  %d\n", in->B[0]);
	printf("B[1]:  %d\n", in->B[1]);
	printf("B[2]:  %d\n", in->B[2]);
}

/**
*@brief Function to create deep copy of a struct
*@param original Pointer
*@param copy     Pointer
*/
void deep_copy(struct example_struct const *const original, struct example_struct *const copy)
{
    copy->name = malloc(strlen(original->name) + 1); // +1 for '\0'
    strcpy(copy->name, original->name);
   
    copy->class = original->class;
    
    copy->q = original->q;
   
    copy->w = original->w;
   
    copy->A = malloc(sizeof(double));
    *(copy->A) = *(original->A);
  
  
    for (int i = 0; i < DIM; i++){
        copy->B[i] = original->B[i];
    }
}
