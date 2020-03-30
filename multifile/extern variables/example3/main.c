#include <stdio.h>

extern int a;
extern int b;

void swap(){
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    printf("first value = %d\t second value = %d\n", a, b);
    swap();
    printf("after swap\n");
    printf("first value = %d\t second value = %d\n", a, b);
    return 0;
}
