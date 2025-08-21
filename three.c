//==============================
// includes and defines
//==============================
#include <stdio.h>      /* header file for C I/O functions */
#include <stdlib.h>     /* other useful funcitons */
#include <string.h>     /* C-string functions */
#include <math.h>       /* math functions */
#include <time.h>

#define FALSE 0
#define TRUE 1


//==============================
// user defined types
//==============================
typedef int bool;

struct node{
    int value;
    struct node *next;
};

typedef struct node Node;
typedef struct node * List;


//==============================
// global variables
//==============================
int minval;
long gvalue2 = 55;


//==============================
// function prototypes
//==============================
List list_create();
bool list_isempty(List l);
bool list_append(List *l, int n);
void list_destroy(List *l);
void list_print(List l);
int max(List l);
bool min(int *minval, List l);
double average(List l);


//==============================
// main function
//==============================
int main(int argc, char *argv[]){
    /* local variables */
    int ii;
    int n;
    List values;

    // get value of n from command line
    if(argc == 0){
        printf("Usage: argv[0] n\n");
        exit(0);
    }
    else
        n = atoi(argv[1]);

    // initalize the list;
    values = list_create();
    
    // load random integers into the values array
    srand(time(NULL));
    for(ii=0; ii<n; ii++)
        list_append(&values, rand() % n);
    
    // print the values out to standard output
    list_print(values);

    // print out stuff about the value array
    printf("The maximum is %d\n", max(values));
    min(&minval, values);
    printf("The minimum is %d\n", minval);
    printf("The average is %lf\n", average(values));
    
    // free the storage
    list_destroy(&values);
        
    // return to calling environment
    return(0);
}


//==============================
// create list function
//==============================
List list_create(){
    return(NULL);
}


//==============================
// is empty list function
//==============================
bool list_isempty(List l){
    return(l == NULL);
}


//==============================
// list append function
//==============================
bool list_append(List *l, int n){
    // local variables
    Node *nn;
    List cur;
    List prev;
    bool retval;
    
    // local variables
    nn = NULL;
    cur = *l;
    prev = NULL;
    retval = FALSE;

    // get to the end of the list
    while(cur != NULL){
        prev = cur;
        cur = cur->next;
    }
    
    // allocate a new node, assign values
    nn = (Node*)malloc(sizeof(Node));
    if(nn != NULL){
        retval = FALSE;
    
        nn->value = n;
        nn->next = NULL;
        
        // check if empty list to begin with...
        if(prev == NULL)
            *l = nn;
        else
            prev->next = nn;
        
        retval = TRUE;
    }

    return(retval);
}


//==============================
// list destroy function
//==============================
void list_destroy(List *l){
    // local variables
    List prev;
    
    // initialize local variables
    prev = NULL;
    
    while(*l != NULL){
        prev = *l;
        *l = (*l)->next;
        free(prev);
    }
}


//==============================
// list print function
//==============================
void list_print(List l){
    // local variables
    List cur;
    int ii;
    
    // initialize local variables
    cur = l;
    ii = 0;
    
    while(cur != NULL){
        printf("%3d ", cur->value);
        ii++;
        if((ii%10)==0)
            printf("\n");
        cur = cur->next;
    }
}


//==============================
// find max value function
//==============================
int max(List l){
    // local variables
    List cur;
    int maxval = -999;

    cur = l;
    while(cur != NULL){
        if(maxval < cur->value)
            maxval = cur->value;
        cur = cur->next;
    }
    
    // return to calling function
    return(maxval);
}


//==============================
// find min value function
//==============================
bool min(int *minval, List l){
    /* local variables */
    bool retval = FALSE;
    List cur;
    
    cur = l;
    
    if(!list_isempty(l)){
        retval = TRUE;
        *minval = 999999999;
        while(cur != NULL){
            if(*minval > cur->value)
                *minval = cur->value;
            cur = cur->next;
        }
    }
    
    /* return to calling function */
    return(retval);
}


//==============================
// average function
//==============================
double average(List l){
    // local variables
    List cur;
    double ave = 0.0;
    double sum = 0;
    int count = 0;
    
    cur = l;
    while(cur != NULL){
        sum += cur->value;
        count++;
        cur = cur->next;
    }
    
    ave = sum / count;
    
    return(ave);
}
