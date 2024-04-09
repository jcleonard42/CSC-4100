/*
Name: Jonathan Leonard (jcleonard42)
Class: CSC-4100
Due Date:3/19/2024
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 5
#define NUMBERS_PER_THREAD 20
#define TOTAL_NUMBERS 100


typedef struct ThreadData{  // this structure holds first number assigned to a thread, the last number assigned to it, and the final result of adding all the numbers together
    int start;
    int end;
    int result;
} ThreadData;


void* calculateSum(void* arg) {  // Calculates sum of numbers assigned to each thread
    ThreadData* data = (ThreadData*)arg;
    data->result = 0;  // set result to 0 before loop

    for (int i = data->start; i <= data->end; ++i) // from the start of the numbers assigned to the thread to the end, add number to result attribute
    {
        data->result += i;
    }

    printf("Thread %d sum: %d\n", (data->start - 1) / NUMBERS_PER_THREAD + 1, data->result);  // print sum of each individual thread

    pthread_exit(NULL);
}


int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) // Create designated number of threads (5)
    {
        threadData[i].start = (i * NUMBERS_PER_THREAD) + 1; // creates start number for thread to add
        threadData[i].end = (i + 1) * NUMBERS_PER_THREAD;   // creates last number for thread to add
        if (threadData[i].end > TOTAL_NUMBERS) {
            threadData[i].end = TOTAL_NUMBERS;
        }

        pthread_create(&threads[i], NULL, calculateSum, (void*)&threadData[i]);  // creates threads and calls CalculateSum
    }

    // total up the sums of each thread
    int totalSum = 0;
    for (int i = 0; i < NUM_THREADS; ++i) 
    {
        pthread_join(threads[i], NULL);
        totalSum += threadData[i].result;
    }

    //print total from 1-100
    printf("Total sum of numbers from 1 to %d is: %d\n", TOTAL_NUMBERS, totalSum);

    return 0;
}

