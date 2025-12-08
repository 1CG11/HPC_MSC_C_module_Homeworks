#include <stdio.h>




void print_binary_rep(const unsigned int x)
{
    int count = 0;

    for(int i=0; (x >> i) != 0; i++){
        count += 1;
    }

    printf("The length of the Binary Representation of %d is %d\n", x, count);
    printf("The Binary Representation of %d is ", x);

    for(int j=0; j<count; j++){
        int b = (x >> (count - j - 1)) & 1;
        printf("%d", b);
    }
}


int main(void)
{
    unsigned int x = 200;

    /* Print the binary representation of x */
    print_binary_rep(x);
    printf("\n");

    return 0;
}
