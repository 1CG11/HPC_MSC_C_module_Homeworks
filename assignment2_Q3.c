/**
*@file assignment2_Q3
*@brief Simple program implementing a 2 round Feistal network to  with a trivial round function.
*@author Cillian  Grall
*/

#include <stdio.h>

/**
*@brief Trivial round function of two intergers using the AND operation
*@param part int
*@param subkey int
*/
unsigned int round_fn(const unsigned int, const unsigned int);

/**
*@brief Function to implement a 2 round feistal network
*@param num 
*@param k1
*@param k2
*/
unsigned int feistal(const unsigned in, const unsigned int, const unsigned int);


int main(void)
{
    const unsigned int num =  24242424;
    const unsigned int k1 = 420;
    const unsigned int k2 = 69;

    unsigned int encrypted = feistal(num, k1, k2);

   
    printf("Original: %u\n",num);
    printf("Encrypted: %u\n",encrypted);

    
    unsigned int decrypted = feistal(encrypted, k2, k1);

    printf("Decrypted: %u\n",decrypted);


return 0;
}


unsigned int round_fn(const unsigned int part, const unsigned int subkey)
{
    unsigned int rounded = part & subkey;
    
    return rounded;
}

unsigned int feistal(const unsigned int input_num, const unsigned int subkeyk1, const unsigned int subkeyk2)
{
    
    /*STEP1:Split up the binary representation of the input number 'num' 
    *into a left (L0) and right (R0) part using the AND operation,
    * using the integers 0xFFFF0000 (hexadecimal), which is 4294901760 
    * and 0x0000FFFF (hexadecimal), which is 65535 in decimal.
    */

    unsigned int L0 = (input_num & 0xFFFF0000)>>16;
    unsigned int R0 = (input_num & 0x0000FFFF);

    /*STEP2*/
    unsigned int L1 = R0;
    unsigned int R1 = L0 ^ round_fn(R0,subkeyk1);

    /*Step3*/
    unsigned int L2 = L1 ^ round_fn(R1,subkeyk2);
    unsigned int R2 = R1;


    /*Step4*/
    /*Recombining the left and right parts to form one new integer*/
    unsigned int out = (L2 << 16) | R2;

    return out;
}

