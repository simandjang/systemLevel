#include <stdio.h>
int main() {
	FILE *fp;
	int key = 9;
	fp = fopen("mesage1.txt", "r");
	char c = fgetc(fp);
	while (c != EOF) {
		
		if (c >= 'a' && c <= 'z') {
			printf("%c", ((c - 'a' + key) % 26) + 'a');
		} else if (c >= 'A' && c <= 'Z') {
			printf("%c", ((c - 'A' + key) % 26) + 'A');
		} else {
			printf("%c", c);
		}
		c = fgetc(fp);
	}
	
	

	fclose(fp);
	
	return 0;
}

