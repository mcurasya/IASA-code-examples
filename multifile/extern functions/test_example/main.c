#include "test.h" //connect our testing library
#include <stdio.h> //connect io library

int main()
{
    //check for assert_equals_int
    int a, b;
    a = 5;
    b = 6;
    printf("5 == 6 equals %d\n", assert_equals_int(a, b));
    b = 5;
    printf("5 == 5 equals %d\n", assert_equals_int(a, b));
    //check for assert_equals_float
    float a1=0.1, b1=0.2;
    printf("just pure equality: %d\n", a1 + b1 == 0.3); 
    printf("with our assert: %d\n", assert_equals_float(a1 + b1, 0.3, 0.0001));
}