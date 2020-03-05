#include <stdio.h>

extern int func1();

extern void func2();

int main(){
    printf("%d\n",func1());
    func2();
    return 0;
}