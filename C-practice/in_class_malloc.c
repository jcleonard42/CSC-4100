#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, *ptr, sum = 0;

    ptr = (int*) malloc(n * sizeof(int));  // from hint
    
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }

    printf("Enter 10 integers:\n", n);

    for (int i = 0; i < 10; i++) {
        scanf("%d", ptr + i); 
        sum += *(ptr + i); // from hint
    }

    printf("Sum of the 10 integers: %d\n", sum);

    free(ptr); // Free the allocated memory (from hint)

    return 0; 
}