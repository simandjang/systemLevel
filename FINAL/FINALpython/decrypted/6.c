#include <stdio.h> 
#include <string.h>
void convert(char *numb){  
	char *ones[19] = {"one", "two", "three", "four","five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *tens[8] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"}; 
	
	int i = atoi(numb), j, k;
	if(i < 20) {
		printf("%s\n", ones[i - 1]);
	}else if (i == 40){
		printf("\n");
	}else if(i >= 20 && i % 10 == 0){
		printf("%s\n", tens[i / 10 - 2]);
	} else {

		printf("%s-", tens[i / 10 - 2]);
                printf("%s\n", ones[i % 10 - 1]);

	}
	
} 
  
int main(void) { 
	convert("8");  
	convert("10"); 
	convert("40");
	convert("22");
	convert("30");
	return 0; 
} 
