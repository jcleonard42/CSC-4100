/* 
Name: Jonathan Leonard
Class: CSC 4100
Professor: Rajesh Manicavasagam
Date: 2/6/2023
*/
#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, *ptr, sum = 0;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));  // from hint
    
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i); 
        sum += *(ptr + i); // from hint
    }

    printf("Sum of the %d integers: %d\n", n, sum);

    free(ptr); // Free the allocated memory (from hint)

    return 0; 
}
