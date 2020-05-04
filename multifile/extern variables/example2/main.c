#include <stdio.h>

extern void set_a(char *);
extern char *get_a();
extern void show_a();
int main()
{
    show_a();                //is not visible in this file even with extern keyword
    printf("%s\n", get_a()); //so we should use visible functions
    set_a("IASA THE BEST");
    show_a();
}