/*
Names: Ethan Adams (eradams42), Jonathan Leonard (jcleonard42), Jake Douthit (jdouthit42), Victor (vhbattonya42)
Class: CSC-4100-002
Assignment: Homework 2 - IPC
Due Date: 3/8/2024
*/

//https://sites.cc.gatech.edu/classes/AY2010/cs4210_fall/code/ProducerConsumer.c
#include<pthread.h>
#include <stdio.h>
#include<unistd.h>
#include<time.h>
#include <stdlib.h>
#include <string.h>

/* Producer/consumer program illustrating conditional variables */

/* Size of shared buffer */
#define MAX_STRING_LENGTH 100
#define BUF_SIZE 3

char buffer[BUF_SIZE][MAX_STRING_LENGTH];
int add=0;										/* place to add next element */
int rem=0;										/* place to remove next element */
int num=0;										/* number elements in buffer */
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;	/* mutex lock for buffer */
pthread_cond_t c_cons=PTHREAD_COND_INITIALIZER; /* consumer waits on this cond var */
pthread_cond_t c_prod=PTHREAD_COND_INITIALIZER; /* producer waits on this cond var */

void *producer(void *param);
void *consumer(void *param);

int main (int argc, char *argv[])
{
	pthread_t tid1, tid2;		/* thread identifiers */
	int i;

	/* create the threads; may be any number, in general */
	if (pthread_create(&tid1,NULL,producer,NULL) != 0) {
		fprintf (stderr, "Unable to create producer thread\n");
		exit(1);
	}
	if (pthread_create(&tid2,NULL,consumer,NULL) != 0) {
		fprintf (stderr, "Unable to create consumer thread\n");
		exit(1);
	}
	/* wait for created thread to exit */
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf ("Parent quiting\n");

    return 0;
}


void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/* Produce value(s) */
void *producer(void *param)
{
	int i;
	char input[100];

	for (i=1; i<=5; i++) {
		/* Get user input */
        printf("Enter a string: ");
        fflush(stdout);
        fgets(input, sizeof(input), stdin);
        /* Remove the newline character from the input */
        input[strcspn(input, "\n")] = '\0';
		
		/* Insert into buffer */
		pthread_mutex_lock (&m);
		if (num > BUF_SIZE) exit(1);	/* overflow */
		while (num == BUF_SIZE)			/* block if buffer is full */
			pthread_cond_wait (&c_prod, &m);
		/* if executing here, buffer not full so add element */
        strcpy(buffer[add], input);
		add = (add+1) % BUF_SIZE;
		num++;
		pthread_mutex_unlock (&m);
		pthread_cond_signal (&c_cons);
		printf ("producer: inserted %s\n", input);  
		fflush (stdout);
        sleep(2);
	}
	printf ("producer quiting\n");  fflush (stdout);
}

/* Consume value(s); Note the consumer never terminates */
void *consumer(void *param)
{
	char output[100];
	int i;

	while (1) {
		pthread_mutex_lock (&m);
		if (num < 0) exit(1);   /* underflow */
		while (num == 0)		/* block if buffer empty */
			pthread_cond_wait (&c_cons, &m);
		/* if executing here, buffer not empty so remove element */
		// Copy the string from the buffer to output
        strcpy(output, buffer[rem]);
		rem = (rem+1) % BUF_SIZE;
		num--;
		pthread_mutex_unlock (&m);
		pthread_cond_signal (&c_prod);
		reverseString(output);
		printf ("Consume value %s\n", output);  
		fflush(stdout);
	}
}