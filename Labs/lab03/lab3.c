
/*
 * Grayson Buchholz
 * CMPS 2300
 * lab3: fork - wait - exec
 * 02/05/2020
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

// Function declarations
int q1();
int q2();
int q3();
int q4();
int q5();
int q6();
int q7();

int main(int argc, char const *argv[])
{

	q1();
	q2();
	q3();
	q4();
	q5();
	q6();
	q7();
	
	return 0;
}

// Question 1
// The variable in the child process
// They both change the value in their respective processes
int q1() {

	int x = 50;
	// Fork function call
	int child = fork();

	if(child < 0) {
		// Fork fails if child < 0
		printf("Fork failed\n");
		exit(1);
	} else if(child == 0) {
		x = 51;
		printf("child process: %d\n", x);
	} else {
		x = 52;
		printf("child process: %d\n", x);
	}

	return 0;
}

// Question 2
// They both can access the descriptor
// One process overwrites the other
int q2() {

	int child = fork();
	int file = open("file.txt", O_RDWR | O_CREAT);
	write(file, "First line\n", strlen("First line\n"));

	if(child < 0) {
		printf("Fork failed\n");
		exit(1);
	} else if(child == 0) {
		write(file, "child line\n", strlen("child line\n"));
	} else {
		write(file, "parent line\n", strlen("parent line\n"));
	}

	FILE *f; 
	char c;
	f = fopen("file.txt", "r");
	int counter = 0;

	while(1) {
		c = fgetc(f);
		if(c == EOF)
			break;
		else {
			printf("%c", c);
			counter++;
		}
	}
	fclose(f);

	return 0;
}

// Question 3
// Use kill()
int q3() {

	int parent_pid = getpid();
	int child = fork();

	if(child < 0) {
		printf("Fork failed\n");
		exit(1);
	} else if(child == 0) {
		kill(parent_pid, SIGCONT);
		printf("hello\n");
	} else {
		printf("goodbye\n");
		pause();
	}
	return 0;
}

// Question 4
// They are C language prototypes
int q4() {

	int child = fork();

	if(child < 0) {
		printf("Fork failed\n");
		exit(1);
	} else if (child == 0) {
		execl("/bin/ls", "ls", "-l", "-a", "-h", NULL);
		execlp("ls", "ls", "-l", "-a", "-h", NULL);
        execle("/bin/ls", "ls", "-l", "-a", "-h", NULL);
        execv("/bin/ls", NULL);
        execvp("ls", NULL);
        execvpe("ls", NULL);  
	}
	return 0;
}

// Question 5
// When successful, returns pid of child, otherwise, returns -1
// -1 is returned
int q5() {

	int child = fork();

	if(child < 0) {
		printf("Fork failed\n");
		exit(1);
	} else if(child == 0) {
		pid_t waitValue = wait(NULL);
		printf("parent waitValue: %d\n", waitValue);
	}
	return 0;
}

// Question 6
// waitpid() waits for child process termination
int q6() {

	pid_t child = fork();
	int waitStatus;

	if(child < 0) {
		printf("Fork failed\n");
		exit(1);
	} else if(child == 0) {
		pid_t  waitpidValue = waitpid(-1, NULL, WUNTRACED | WCONTINUED);
		printf("child waitValue: %d\n", waitpidValue);
	} else {
		pid_t waitpidValue = waitpid(child, &waitStatus, WUNTRACED | WCONTINUED);
		printf("parent waitValue: %d\n", waitpidValue);
	}
	return 0;
}

// Question 7
// printf() will not appear in terminal
int q7() {

	pid_t child = fork();

	if(child < 0) {
		printf("Fork failed\n");
		exit(1);
	} else if(child == 0) {
		close(STDOUT_FILENO);
		printf("child printf()");
	}
	return 0;
}
