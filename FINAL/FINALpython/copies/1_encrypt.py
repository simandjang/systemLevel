#!/usr/bin/python

def encrypt_9(ch, key):
	result = ""
	for char in ch:
		if (char >= 'A' and char <= 'Z'):
			result += chr((ord(char) + key - 65) % 26 + 65)
		elif (char >= 'a' and char <= 'z'):
			result += chr((ord(char) + key - 97) % 26 + 97)
		else:
			result += char
	return result




f = open("caesar1.txt", "r")
ch = f.read()
key = 23
print(encrypt_9(ch, key))
f.close()

