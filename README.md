# P196-Numbers
This prints out all P196 numbers within a ULONG_MAX and the palindrome number that is associated with it. Before we can talk
about P196 numbers, we need to first talk about palindrome numbers. A palindrome number is a number that when flipped is still equal to it's original value, for example; 1456 is not a palindrome number because when it's flipped 6541 does not equal 1456. However, 2002 when flipped is 2002 and therefore 2002 is a palindrome number!  A P196 number is a number that when flipped and added to itself eventually becomes a palindrome number. For example, 10 is not a palindrome number because when it is flipped the value is 01.  However, when we add 10 to it's flipped value 1, we get 11 and 11 IS a palindrome number, therefore 10 is a P196 Value! This program written in C++ finds all P196 numbers within a ULONG_MAX (where ULONG_MAX is the highest value that an unsigned long variable can be without overflowing) without using arrays, vectors, or strings or characters.  All functions are written by myself, I used no standard library functions within this program.    
