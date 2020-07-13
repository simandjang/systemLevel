#include <stdio.h>
int main() {
	FILE *fp;
	fp = fopen("caesar1.txt", "r");
	char c = fgetc(fp);
	int numbers[26] = {0}, t, i, n, max = 0;
	while(c != EOF){
		if(c >= 'a' && c <= 'z') {
			t = c - 'a';
			numbers[t]++;
		} else if (c >= 'A' && c <= 'Z') {
			t = c - 'A';
			numbers[t]++;
		} else {
			n++;
		}
		c = fgetc(fp);
	}
	for(i = 0; i < 26; i++) {
		printf("%c, %d\n", i + 'a', numbers[i]);
	}
	fclose(fp);
	return 0;

}
