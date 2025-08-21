#include <stdio.h>
#include <stdlib.h>

void show_bytes(unsigned char *start, size_t len);
void show_char(char c);
void show_short_int(short int si);
void show_int(int i);
void show_float(float f);
void show_double(double d);
void show_long_double(long double ld);

int main(){
    /* local variables */
    char c = 'M';
    short si = 42;
    int i = 30203;
    float f = 1.0f;
    double d = 1.0;
    long double ld = 1.0L;
    char *pc;
    short *psi;
    int *pi;
    float *pf;
    double *pd;
    long double *pld;
    
    
    pc = &c;
    psi = &si;
    pi = &i;
    pf = &f;
    pd = &d;
    pld = &ld;

    printf("Size of char is:           %ld\tSize of char * is:        %ld\n", sizeof(char),   sizeof(char*));
    printf("Size of short int is:      %ld\tSize of short int * is:   %ld\n", sizeof(short),  sizeof(short*));
    printf("Size of int is:            %ld\tSize of int * is:         %ld\n", sizeof(int),    sizeof(int*));
    printf("Size of float is:          %ld\tSize of float * is:       %ld\n", sizeof(float),  sizeof(float*));
    printf("Size of double is:         %ld\tSize of double * is:      %ld\n", sizeof(double), sizeof(double*));
    printf("Size of long double is:    %ld\tSize of long double * is: %ld\n", sizeof(long double), sizeof(long double*));

    printf("\n");

    show_char(c);
    show_short_int(si);
    show_int(i);
    show_float(f);
    show_double(d);
    show_long_double(ld);

    printf("\n");

    printf("Character c is at address    %p and has value '%c'\n", &c, c);
    printf("Short int si is at address   %p and has value %d\n", &si, si);
    printf("Int i is at address          %p and has value %d\n", &i, i);
    printf("Float f is at address        %p and has value %f\n", &f, f);
    printf("Double d is at address       %p and has value %lf\n", &d, d);
    printf("Long double ld is at address %p and has value %Lf\n", &ld, ld);

    printf("\n");

    printf("Character * pc is at address    %p and has value %p\n", &pc, pc);
    printf("Short int * psi is at address   %p and has value %p\n", &psi, psi);
    printf("Int * pi is at address          %p and has value %p\n", &pi, pi);
    printf("Float * pf is at address        %p and has value %p\n", &pf, pf);
    printf("Double * pd is at address       %p and has value %p\n", &pd, pd);
    printf("Long double * pld is at address %p and has value %p\n", &pld, pld);

    return 0;
}


void show_bytes(unsigned char *start, size_t len){
  int i;
  for(i=0; i<len; i++)
    printf(" %.2x", start[i]);
  printf("\n");
}

void show_char(char c){
  show_bytes((unsigned char*)&c, sizeof(char));
}

void show_short_int(short int si){
  show_bytes((unsigned char*)&si, sizeof(short int));
}

void show_int(int i){
  show_bytes((unsigned char*)&i, sizeof(int));
}

void show_float(float f){
  show_bytes((unsigned char*)&f, sizeof(float));
}

void show_double(double d){
  show_bytes((unsigned char*)&d, sizeof(double));
}

void show_long_double(long double ld){
  show_bytes((unsigned char*)&ld, sizeof(long double));
}
