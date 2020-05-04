#define SQR(x) x*x
#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("%d\n", SQR(5)); //will compute correctly
    printf("%c", SQR('\t'));  //still is computable but logically incorrect
    return 0;
}
