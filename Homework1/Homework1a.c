#include <stdio.h>
/*
 * @brief Approximates Euler's number 'e' using the limit definition.
 *
 * Uses the formula (1 + 1/n)^n for increasing values of n up to 1e8.
 * Prints approximations to 8 decimal places.
 */

int main(void)
{
		for(int i=1; i<=100000000; i*=10){
			double base = (1+(1/(double)i));

			double result = 1;

				for(int j=1; j<=i; j++){

					result=result*base;
				}
			printf("Approximation when n=%d is %0.8f\n",i,result);

		}
}
