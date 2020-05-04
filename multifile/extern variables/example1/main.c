#include <stdio.h>

extern int var;
int main(){
	printf("%d", var); //is visible in this file with extern
	return 0;
}
