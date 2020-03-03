#include <stdio.h>
#include "dependency2.c"
#include "dependency1.c"
//extern int func1();

//extern void func2();

int main(){
    printf("%d\n",func1());
    func2();
    return 0;
}