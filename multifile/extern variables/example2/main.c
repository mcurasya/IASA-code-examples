#include <stdio.h>

extern void set_a(char*);
extern char* get_a();
extern void show_a();
int main() {
    show_a();
    printf("%s\n", get_a());
    set_a("FICT sucks");
    show_a();
}