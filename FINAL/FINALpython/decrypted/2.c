#include <stdio.h>


int main() {
	char inputstr [20];
	printf("Type an input \n");
	scanf("%s",inputstr);
	int a;
	a = atoi(inputstr);
	printf("You entered %d (as an integer)\n", a);
	return 0;

}
