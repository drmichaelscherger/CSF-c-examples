#include <stdio.h>
#include <stdlib.h>

void show_bytes(unsigned char *start, size_t len);
void show_char(char c);

int main(){
    /* local variables */
    char c = 'M';
    char *pc;
    
    
    pc = &c;

    printf("Size of char is:           %ld\tSize of char * is:      %ld\n", sizeof(char),   sizeof(char*));

    printf("\n");

    show_char(c);

    printf("\n");

    printf("Character c is at address   %p and has value '%c'\n", &c, c);

    printf("\n");

    printf("Character * pc is at address    %p and has value %p\n", &pc, pc);

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

