#include <stdio.h>

int main() {
	int i, j, mul;
	int max = 0;
	for(i = 999; i > 100; i--) {
		for(j = 999; j > 100; j--) {
			mul = i * j;
			if(palindrome(mul) && mul > max) {
				max = mul;
			}
		}
	}
	printf("The largest palindrome made by product of 2 three digit number is %d\n",max);
	return 0;
}
int palindrome(int n) {
	int reverse = 0, rv = n;
	while(rv) {
		reverse = 10*reverse + (rv % 10);
		rv /= 10;	
	}
	return reverse == n;
}
