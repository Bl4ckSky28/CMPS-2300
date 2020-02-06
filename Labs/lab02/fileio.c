/*
 * Grayson Buchholz
 * CMPS 2300
 * lab1pr2: File IO
 * 01/29/2020
 */

#include <stdio.h>

int main(int argc, char const *argv[]) {

	// Pointer to file
	FILE *file;
	// Variable to read content of file
	char c;
	// Opens file in read only mode
	file = fopen("file.txt", "r");

	int counter = 0;
	c = fgetc(file);
	int idleTime[c];

	// Loop through file and assign values to array
	while(1) {
		c = fgetc(file);
		if(c == EOF) 
			break;
		else {
			idleTime[counter] = c;
			counter++;
		}
	}
	fclose(file);

	
	// Computes total idle time
	int totalIdleTime = 0;
	for(int i = 0; i < 7; i++) {
		totalIdleTime += idleTime[i];
	}

	// Computes performance rate
	float performanceRate = (totalIdleTime / 10080.0) * 100.0;

	// Computes average idle time
	int averageIdleTime = totalIdleTime / 7;

	// Computes highestLoadDay 
	int min = idleTime[0];
	int highestLoadDay = 1;
	for(int i = 0; i < 7; i++) {
		if(idleTime[i] < min) {
			min = idleTime[i];
			highestLoadDay = i + 1;
		}
	}
	// Computes lowestLoadDay
	int max = idleTime[0];
	int lowestLoadDay = 1;
	for(int i = 0; i < 7; i++) {
		if(idleTime[i] > max) {
			max = idleTime[i];
			lowestLoadDay = i + 1;
		}
	}

	printf("totalIdleTime: %d\n", totalIdleTime);
	printf("performanceRate: %f\n", performanceRate);
	printf("averageIdleTime: %d\n", averageIdleTime);
	printf("highestLoadDay: %d\n", highestLoadDay);
	printf("lowestLoadDay: %d\n", lowestLoadDay);


	return 0;
}
