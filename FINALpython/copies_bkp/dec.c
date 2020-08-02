#include <stdio.h>

int main() {
	FILE *fp;
	fp = fopen("caesar2.txt", "r");
	char c = fgetc(fp);
	int key, i, t, n, k, max = 0, numbers[26] = {0};
	while(c != EOF){
		if(c >= 'a' && c <= 'z'){
			t = c - 'a';
			numbers[t]++;	
		} else if(c >= 'A' && c <= 'Z'){
			t = c - 'A';
			numbers[t]++;
		}else {
			n++;
		}
		c = fgetc(fp);
	}
	for(i = 0; i < 26; i++) {
		printf("%c, %d\n", i + 'a', numbers[i]);
		if(numbers[i]> max) {
			k =(i + 'a' - 'e' + 25) % 26; 
		}
	}
	 printf("\n");
	 printf("////The key for dectyption is: %d////\n\n", k);

	fclose(fp);
	fp = fopen("caesar2.txt", "r");
	char d = fgetc(fp);
	while(d != EOF) {
		if(d >= 'a' && d <= 'z'){
			printf("%c", ((d - 'a' + k)% 26) + 'a');
		} else if (d >= 'A' && d <= 'Z'){
			printf("%c", ((d - 'A' + k)% 26) + 'A');	
		} else {
			printf("%c", d);
		}
		d = fgetc(fp);
	}
	
	fclose(fp);
	return 0;

}
