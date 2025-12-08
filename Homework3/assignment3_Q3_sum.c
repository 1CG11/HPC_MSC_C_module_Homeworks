/*
*@brief Function to compute the sum of the squares of an array recursively
*@param *arr    Pointer
*@param n       int
*/
double sumsq_recur(const double *arr, const int n)
{
    if(n==0){
        return 0;
    }

    return (arr[n-1]*arr[n-1]) + sumsq_recur(arr,n-1);
}
