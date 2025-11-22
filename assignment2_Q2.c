/**
*@file assignment2b.c
*@brief Simple program to print the representation of chmod octal permissions
* i.e. given an octal input of 0755, it will print "rwxr-xt-x" to the screen
*@author Cillian Grall
*@version 1.0
*@date 2025-10-30
*/
#include <stdio.h>
#include <stdlib.h>

/**
* @brief Print the "rwx" equivalent representation of a chmod mode
*
*@param[in] int The number which we will print
*/
void print_mode(unsigned short const in){
    /*Check whether input is valid */
    if(in>0777){
        printf("Error. Not-a-valid-mode");
        exit(1);
    }

    /*Print input as an octal number */
    printf("%o:\t",in);
    
    /*Breaking up the 3 digit blocks of the octal and storing them*/
    unsigned int a=(in >>6 ) & 7;
    unsigned int b=(in >> 3) & 7;
    unsigned int c=in & 7;

    printf("The file permissions associated with the given octal mode is:");

    /*Print statements to match the permissions associated with each block*/
    if( a & 4 ) printf("r") ; else printf("-");
    if( a & 2 ) printf("w") ; else printf("-");
    if( a & 1 ) printf("x") ; else printf("-");


    if( b & 4 ) printf("r") ; else printf("-");
    if( b & 2 ) printf("w") ; else printf("-");
    if( b & 1 ) printf("x") ; else printf("-");


    if( c & 4 ) printf("r") ; else printf("-");
    if( c & 2 ) printf("w") ; else printf("-");
    if( c & 1 ) printf("x\n") ; else printf("-\n");

}

int main(void)
{
    unsigned short mode = 0754; /*Octal number */
    print_mode(mode);   /*Print "rwx" equivalent of mode*/

    mode=0623;
    print_mode(mode);

    return 0;
}
