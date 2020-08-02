#include <stdio.h>
#include <stdlib.h>

int main() {
	char *a;
	size_t asize = 32;
	size_t charac;
	a = (char *)malloc(asize * sizeof(char));
	printf("Type something: ");
	charac = getline(&a, &asize, stdin);
	printf("You typed: %s \n",a);
	return 0;
}
q
