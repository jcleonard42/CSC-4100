/*
Names: Jonathan Leonard (jcleonard42)
Assignment: Homework 1 - Processes
Professor: Dr. Manicavasagam
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int x = 100;
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) { // fork failed; exit
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (pid == 0) { // Child process
        printf("Child process: x = %d\n", x);
        x = 50; // Change the value of x in the child process
        printf("Child process: Changed x = %d\n", x);
    } 
    else { // Parent process
        printf("Parent process: x = %d\n", x);
        x = 150; // Change the value of x in the parent process
        printf("Parent process: Changed x = %d\n", x);
    }

    return 0;
}