#include <stdio.h>


double sumsq_recur(const double *arr, const int n);


int main(void)
{
    double x[]={2,4,6};

    int n = 3;

    double result = sumsq_recur(x,n);

    printf("The result from the recursive sum is = %.2lf \n",result);

    return 0;
}


