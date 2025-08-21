#include <stdio.h>
#include <stdlib.h>



void swap(int *a, int *b);


int main(){

    // local variables
    int x;      // a direct variables 
    int *px;    // A pointer is an indirect reference to a memory location
    int y;

    // initialize variables
    x = 0;
    px = NULL;


    x = 5;
    y = 500;
    px = &x;


    printf("%p is at location %p\n", px, &px);
    printf("%p is at location %p\n", px, &px);

    // dereference operator
    *px = *px + 1;
    printf("%d is at location %p\n", *px, px);

    // example calling a function that passes args by reference
    swap(&x, &y);
    printf("%d %d", x, y);

    return(0);
}




void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
