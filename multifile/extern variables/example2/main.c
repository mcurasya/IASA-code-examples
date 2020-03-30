#include <stdio.h>

extern char* get_a();
extern void show_a();
int main() {
    show_a();
    printf("%s\n", get_a());
}