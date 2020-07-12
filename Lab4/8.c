#include <stdio.h>
#include <string.h>
void mul(int a, int b) {

        printf("%d\n", a * b);

}
void convert2(char *st1, char *st2) {
	char *ones[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *tens[8] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	int numb1 = 0;
	if (strstr(st1, "-") != NULL) {
		char numberst[30];
		strcpy(numberst, st1);
		char *part;
		part = strtok(numberst, "-");
		int a;
		for (a = 0; a < (int)sizeof(tens)/sizeof(tens[0]); a++) {
			if (strcasecmp(part, tens[a]) == 0) {
				numb1 += 10 * (a + 2);
				break;
			}
		}	
		part = strtok(NULL, "-");
		int b;
		for (b = 0; b < (int)sizeof(ones)/sizeof(ones[0]); b++) {
			if (strcasecmp(part, ones[b]) == 0) {
				numb1 += b + 1;
				break;
			}
		}
	} else {
		int i;
		int check = 0;
		for (i = 0; i < (int)sizeof(ones)/sizeof(ones[0]); i++){
			if(strcasecmp(st1, ones[i]) == 0) {
				numb1 += (i + 1);
				check = 1;
				break;
			}
		}
		if (!check) {
			int j;
			for(j = 0; j < (int)sizeof(tens)/sizeof(tens[0]); j++) {
				if (strcasecmp(st1, tens[j]) == 0) {
					numb1 += 10 * (j + 2);
					break;
				}
			}
		}
	}
	int numb2 = 0;
        if (strstr(st2, "-") != NULL) {
                char numberst[30];
                strcpy(numberst, st2);
                char *part;
                part = strtok(numberst, "-");
                int a;
                for (a = 0; a < (int)sizeof(tens)/sizeof(tens[0]); a++) {
                        if (strcasecmp(part, tens[a]) == 0) {
                                numb2 += 10 * (a + 2);
                                break;
                        }
                }
                part = strtok(NULL, "-");
                int b;
                for (b = 0; b < (int)sizeof(ones)/sizeof(ones[0]); b++) {
                        if (strcasecmp(part, ones[b]) == 0) {
                                numb2 += b + 1;
                                break;
                        }
                }
        } else {
                int i;
                int check = 0;
                for (i = 0; i < (int)sizeof(ones)/sizeof(ones[0]); i++){
                        if(strcasecmp(st2, ones[i]) == 0) {
                                numb2 += (i + 1);
                                check = 1;
                                break;
                        }
                }
                if (!check) {
                        int j;
                        for(j = 0; j < (int)sizeof(tens)/sizeof(tens[0]); j++) {
                                if (strcasecmp(st2, tens[j]) == 0) {
                                        numb2 += 10 * (j + 2);
                                        break;
                                }
                        }
                }
        }
	mul(numb1,numb2);
}
void convert(char *st) {
	char n[30];
	strcpy(n, st);
        char *st1 = strtok(n, " ");
	char *st2 = strtok(NULL, " ");
        convert2(st1, st2); 

}

int main() {
	convert("Five three");
	convert("Twenty fifteen");		
}

