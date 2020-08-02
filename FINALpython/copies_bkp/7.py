#!/usr/bin/python

ones = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]

word = raw_input("Enter a word for an integer: ")
ws = word.split('-')
if len(ws)< 2:
	for x in range(len(ones)):
		if ws[0] == ones[x] or ws[0].lower() == ones[x]:
			print(x + 1)
	for y in range(len(tens)):
		if ws[0] == tens[y] or ws[0].lower() == tens[y]:
			print((y + 2) * 10)
else:
	for x in range(len(tens)):
		if ws[0] == tens[x] or ws[0].lower() == tens[x]:
			t = (x + 2) * 10
	for y in range(len(ones)):
		if ws[1] == ones[y] or ws[1].lower() == ones[y]:
			o = y + 1
	print(t + o)
