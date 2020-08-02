#!/usr/bin/python


f = open("caesar2.txt", "r")
ch = f.read()
numbers = {}
maxi = 0
maxc = ''
for char in ch:
        if char.isalpha():
		if char in numbers:
                        numbers[char] += 1
			if numbers[char] > maxi:
				maxi = numbers[char]
				maxc = char
                else:
                        numbers[char] = 1
print (str(numbers))
print("The maximum occurence character is: " + maxc)
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




f = open("caesar2.txt", "r")
ch = f.read()
key = ord('z') - ord('a') - ord(maxc) + ord('e') + 1
print(encrypt_9(ch, key))
 
f.close()



