#include <stdio.h>

extern int func1();

extern void func2(int a);

int main(){
    printf("%d\n",func1());
    func2(5);
    return 0;
}