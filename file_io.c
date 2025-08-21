#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]){
    // local variables
    FILE *infile;
    int n = 0;
    int *arr;
    int ii = 0;



    // open the file
    infile = fopen(argv[1], "r");

    // read in the number of data points
    fscanf(infile, "%d", &n);


    // allocate storage for the array
    arr = (int *) malloc(n * sizeof(int));

    // read in the data values
    for(ii=0; ii<8; ii++){
        fscanf(infile, "%d", &arr[ii]);
    }
    

    // echo the array
    for(ii=0; ii<8; ii++){
        printf("%d\n", arr[ii]);
    }

    // free the storage
    free(arr);


    // close the file
    fclose(infile);

    return(0);
}