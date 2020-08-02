#!/usr/bin/python

f = open("caesar1.txt", "r")
ch = f.read()
numbers = {}
for char in ch:
	if char.isalpha():

		if char in numbers:
			numbers[char] += 1
		else:
			numbers[char] = 1
print (str(numbers))
f.close()	
