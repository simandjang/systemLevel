import os

def encrypt(file_name):
        key = 150
        input_f = open('encrypted/' + file_name)
        ch = input_f.read()
        result = ""
        for c in ch:
                result += chr((ord(c) - key) % 256)
                key = (key - 1) % 256
        input_f.close()
        output_f = open('decrypted/' + file_name, "w")
        output_f.write(result)
        output_f.close()

for afile in os.listdir('encrypted'):
        encrypt(afile)

