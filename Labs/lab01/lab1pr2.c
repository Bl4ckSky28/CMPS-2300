/*
 * Grayson Buchholz
 * CMPS 2300
 * lab1pr2: Hex Verifier
 * 01/29/2020
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function declaration
bool isHex(char str[]);

int main(int argc, char const *argv[]) {	

	char str[20];
	// Assign user input to char array
	printf("Enter a character sequence: ");
	scanf("%s", str);

	bool correct = isHex(str);

	// Loop until hex number is valid
	while(!correct) {
		printf("Enter a character sequence: ");
		scanf("%s", str);
		correct = isHex(str);
	}

	printf("Thank you!\n");

	return 0;
}

bool isHex(char str[]) {
	// Empty string
	if(strlen(str) == 0) {
		return false;
	} else {
		// Loop through character array and determine if it is hex
		for(int i = 0; i < strlen(str); i++) {
			if(!isxdigit(str[i])) {
				return false;
			}
		}
	}
	return true;
}
