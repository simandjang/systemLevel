#!/usr/bin/python

print("Enter a year: ") 
year = int(input())
if year % 4 == 0: 
	if year % 400 == 0:
		print("It is a leap year")
	elif year % 100 == 0:
		print("It is not a leap year")
	else:
		print("It is a leap year")
else:
	print("It is not a leap year")
