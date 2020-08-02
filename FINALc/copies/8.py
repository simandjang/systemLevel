#!/usr/bin/python

ones = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]

word = raw_input("Enter two word to multiply: ")
ws = word.split(' ')
fw = ws[0].split('-')
sw = ws[1].split('-')

if len(fw)< 2:
	for x in range(len(ones)):
		if fw[0] == ones[x] or fw[0].lower() == ones[x]:
			a = x + 1
	for y in range(len(tens)):
                if fw[0] == tens[y] or fw[0].lower() == tens[y]:
                        a = (y + 2) * 10
else:
	for x in range(len(tens)):
                if fw[0] == tens[x] or fw[0].lower() == tens[x]:
                        t = (x + 2) * 10
        for y in range(len(ones)):
                if fw[1] == ones[y] or fw[1].lower() == ones[y]:
			o = y + 1
	a = t + o

if len(sw)< 2:
        for x in range(len(ones)):
                if sw[0] == ones[x] or sw[0].lower() == ones[x]:
                        b = x + 1
        for y in range(len(tens)):
                if sw[0] == tens[y] or sw[0].lower() == tens[y]:
                        b = (y + 2) * 10
else:
        for x in range(len(tens)):
                if sw[0] == tens[x] or sw[0].lower() == tens[x]:
                        t = (x + 2) * 10
        for y in range(len(ones)):
                if sw[1] == ones[y] or sw[1].lower() == ones[y]:
                        o = y + 1
        b = t + o

print(a * b)


