#!/usr/bin/python

ones = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]

print("Enter any number less than a hundred to convert as word: ")
num = int(input())

if num < 20:
	print(ones[num - 1])
elif num % 10 == 0:
	if num == 40:
		print(" ")
	else:
		print(tens[num / 10 - 2])
else:
	a = num / 10
	b = num % 10
	print(tens[a - 2] + "-" + ones[b - 1])
