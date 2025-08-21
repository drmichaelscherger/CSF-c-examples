//==============================
// includes and defines
//==============================
#include <stdio.h>      /* header file for C I/O functions */
#include <stdlib.h>     /* other useful funcitons */
#include <string.h>     /* C-string functions */
#include <math.h>       /* math functions */
#include <time.h>

#define N 20
#define FALSE 0
#define TRUE 1


//==============================
// user defined types
//==============================
typedef int bool;


//==============================
// global variables
//==============================
int minval;
long gvalue2 = 55;


//==============================
// function prototypes
//==============================
int max(int *v, int n);
bool min(int *minval, int v[], int n);
double average(int *v, int n);


//==============================
// main function
//==============================
int main(int argc, char *argv[]){
    /* local variables */
    int ii;
    int n;
    int *values;

    // get value of n from command line
    if(argc != 2){
        printf("Usage: argv[0] n\n");
        exit(0);
    }
    else
        n = atoi(argv[1]);

    // dynamically allocate the array
    values = (int*)malloc(sizeof(int)*n);
    
    // initialize the values array
    for(ii=0; ii<n; ii++)
        ii[values] = 0;
    
    // load random integers into the values array
    srand(time(NULL));
    for(ii=0; ii<n; ii++)
        values[ii] = rand() % n;
    
    // print the values out to standard output
    ii=0;
    while(ii<n){
        printf("%3d ", values[ii]);
        ii++;
        if((ii % 10) == 0)
            printf("\n");
    }

    // print out stuff about the value array
    printf("The maximum is %d\n", max(values, n));
    min(&minval, values, n);
    printf("The minimum is %d\n", minval);
    printf("The average is %lf\n", average(values, n));
    
    
    // free the storage
    free(values);
        
    // return to calling environment
    return(0);
}


//==============================
// find max value function
//==============================
int max(int v[], int n){
    // local variables
    int ii;
    int maxval = -999;
    
    if(n > 0){
        maxval = v[0];
        for(ii=1; ii<n; ii++)
            if(maxval < v[ii])
                maxval = v[ii];
    }
    
    // return to calling function
    return(maxval);
}


//==============================
// find min value function
//==============================
bool min(int *minval, int v[], int n){
    /* local variables */
    bool retval = FALSE;
    int ii;
    
    if(n > 0){
        retval = TRUE;
        *minval = v[0];
        for(ii=0; ii<n; ii++)
            if(*minval > v[ii])
                *minval = v[ii];
    }
    
    /* return to calling function */
    return(retval);
}


//==============================
// average function
//==============================
double average(int v[], int n){
    // local variables
    int ii;
    double ave = 0.0;
    double sum = 0;
    
    for(ii=0; ii<n; ii++)
        sum += v[ii];
    
    ave = sum / n;
    
    return(ave);
}
