
/*
 * Grayson Buchholz
 * CMPS 2300
 * lab4: C Bitwise Operations
 * 02/05/2020
 */

#include <stdio.h>

// Function declarations
void prefix(unsigned int x, unsigned int n);
void suffix(unsigned int x, unsigned int n);
void toggle(unsigned int x, unsigned int n);
unsigned int binary(unsigned int num);

int main(int argc, char const *argv[])
{
	prefix(10, 2);
	suffix(10, 2);
	toggle(10, 2);
}

// Returns first n bits of number x
void prefix(unsigned int x, unsigned int n) {
	unsigned int newNum;
	newNum = ((1 << n) - 1) & x;
	printf("%d\n", newNum);
	printf("%d\n", binary(newNum));
}

// Returns last n bits of number x
void suffix(unsigned int x, unsigned int n) {
	unsigned int newNum;
	newNum = ((1 >> n) + 1) & x;
	printf("%d\n", newNum);
	printf("%d\n", binary(newNum));
}

// Toggles nth bit of number x
void toggle(unsigned int x, unsigned int n) {
	unsigned int newNum;
	newNum = x ^ (1 << n);
	printf("%d\n", newNum);
	printf("%d\n", binary(newNum));
}

// Converts integer to binary
unsigned int binary(unsigned int num) {
	if(num == 0) 
		return 0;
	else 
		return (num % 2) + 10 * binary(num / 2);
}