#include <stdio.h>
#include <stdlib.h>
//static variable can only be seen inside file, extern keyword won't do a thing, so we need to write our own getter
static char* a = "KA-97";

char* get_a(){
    return a;
}


void show_a(){
    printf("%s\n", a);
}

void set_a(char* value){
    a = value;
}