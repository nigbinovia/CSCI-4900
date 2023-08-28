# CSCI-4900
This repository includes the project I completed in CSCI 4900 - Selected Topics in Computer Science: Cybersecurity 

The project is described below:


Polyalphabetic-Rail Fence Cipher Program 

This program allows you to encrypt and decrypt messages using two different ciphers: Rail Fence Cipher and Polyalphabetic Cipher. Included is the main program file, the test text file, the executable, and the makefile

Rail Fence Cipher: The Rail Fence Cipher is a transposition cipher that rearranges characters in a zigzag pattern. It requires a numeric key to specify the number of rails (rows). The program provides both encryption and decryption using this cipher.

Polyalphabetic Cipher: The Polyalphabetic Cipher is a substitution cipher that uses multiple substitution alphabets to encrypt a message. The program performs both encryption and decryption using this cipher.

The program reads input from a file named test.txt, where each line contains a function number, a key (for Rail Fence Cipher), and a word or phrase to encrypt/decrypt. The function numbers correspond to different operations:

1. Rail Fence Encryption
2. Rail Fence Decryption
3. Polyalphabetic Encryption
4. Polyalphabetic Decryption

For each function, the program performs the appropriate encryption or decryption and displays the result.

All Files in the Same Location: Make sure that all the files included in this package are all in the same location. This is necessary for the makefile to compile the C++ code properly. 

Run the Makefile: Use the command make in your terminal to compile your source code and create/refresh the executable. The basic command format is:
*make*

Run the Executable: Once your code has successfully compiled, run you executable with the following command:
*./main*


