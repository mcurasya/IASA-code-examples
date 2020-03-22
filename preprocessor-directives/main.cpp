#define SQR(x) x*x
#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("%d", SQR(5));
    printf("%c", SQR('\t'));
    return 0;
}
