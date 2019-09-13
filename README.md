
# Automatic Caesar Cipher Breaker

## CIS 241 - Project 1 (Fall 2019)

Caesar ciphers are a basic encryption technique in which each letter in the original text is replaced
by a letter some fixed number of positions down the alphabet. Here, the fixed number of
positions is referred to as the key for the cipher. For example, if the key is 4, then the mapping
between the original and cipher alphabets will be as follows:

> Original: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
> Cipher: E F G H I J K L M N O P Q R S T U V W X Y Z A B C D

Caesar ciphers can be automatically broken by using the known letter frequencies of the language
of the encrypted text. The frequencies for English as given on Wikipedia are available in the file
letFreq.txt that can be found from the instructor’s website.

This program will use this data to crack the code for arbitrary Caesar ciphers.
The input for your program is an encrypted file produced by using the Caesar Cipher with
a key between 0 and 25. Note that in the file, only the letters are changed; all other characters
remain intact and capitalization is preserved.
