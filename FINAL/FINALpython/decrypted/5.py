#!/usr/bin/python

max = 0
for x in range(999,100,-1):
	for y in range(999,100,-1):
		mul = x * y
		if mul > max:
			pal = str(x * y)
			if pal == pal[::-1]:
				max = x * y
print(max)
