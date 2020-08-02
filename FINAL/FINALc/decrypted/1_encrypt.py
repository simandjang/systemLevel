#!/usr/bin/python

def encrypt_9(ch, key):
	result = ""
	for char in ch:
		if (char >= 'A' and char <= 'Z'):
			result += chr((ord(char) + key - 65) % 26 + 65)
