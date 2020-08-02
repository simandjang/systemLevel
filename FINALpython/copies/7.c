#include <stdio.h>
#include <string.h>
void convert(char *st) {
	char *ones[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *tens[8] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	int numb = 0;
	if (strstr(st, "-") != NULL) {
		char numberst[30];
		strcpy(numberst, st);
		char *part;
		part = strtok(numberst, "-");
		int a;
		for (a = 0; a < (int)sizeof(tens)/sizeof(tens[0]); a++) {
			if (strcasecmp(part, tens[a]) == 0) {
				numb += 10 * (a + 2);
				break;
			}
		}	
		part = strtok(NULL, "-");
		int b;
		for (b = 0; b < (int)sizeof(ones)/sizeof(ones[0]); b++) {
			if (strcasecmp(part, ones[b]) == 0) {
				numb += b + 1;
				break;
			}
		}
	} else {
		int i;
		int check = 0;
		for (i = 0; i < (int)sizeof(ones)/sizeof(ones[0]); i++){
			if(strcasecmp(st, ones[i]) == 0) {
				numb += (i + 1);
				check = 1;
				break;
			}
		}
		if (!check) {
			int j;
			for(j = 0; j < (int)sizeof(tens)/sizeof(tens[0]); j++) {
				if (strcasecmp(st, tens[j]) == 0) {
					numb += 10 * (j + 2);
					break;
				}
			}
		}
	}


	printf("%d\n", numb);
}

int main() {
	convert("One");
	convert("ten");
	convert("fifteen");
	convert("Thirteen");
	convert("fourty");
	convert("twenty");
	convert("sixty-two");
	convert("Ninety-nine");
	convert("Fifty-one");	
	
}

