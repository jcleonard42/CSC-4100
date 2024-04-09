/* 
Name: Jonathan Leonard
Class: CSC 4100
Professor: Rajesh Manicavasagam
Date: 1/25/2023
*/

#include <stdio.h>

void hello_world(){
    for (int i = 0; i < 5; i++) {
        printf("Hello, World! \n");
    }

    return;
}

void add(){
    int num1 = 0;
    int num2 = 0;
    printf("Please enter two numbers to be added! \n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 1: ");
    scanf("%d", &num2);
    num1 = num1 +num2;
    printf("%d", num1);

    return;
}

void for_loop(){
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    return;
}

void while_loop(){
    int i = 1;
    while(i <= 10){
        printf("%d ", i);
        i = i + 1;
    }
    return;
}

void factorial(){
    int num = 0;
    int sum = 0;
    printf("Please enter a number to find the factorial: ");
    scanf("%d", &num);
    sum = num;
    num = num-1;
    while(num >= 1){
        sum = sum * num;
        num = num - 1;
    }
    printf("%d", sum);
    return;
}



int main(){
    // switch variable
    int user_choice = 0;

  // switch statement
  while(user_choice !=6){
        printf("\n Please choose an option: \n Option 1: Add Two Numbers \n Option 2: Print numbers 1-10 with for loop \n Option 3: Print numbers 1-10 with while loop \n Option 4: Generate factorial \n Option 5: Print Hello World \n Option 6: Quit ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                add();
                break;
    
            case 2:
                for_loop();
                break;
    
            case 3:
                while_loop();
                break;
    
            case 4:
                factorial();
                break;
            
            case 5:
                hello_world();
                break;
            
        }
    }

    return 0;
}

// Do we need input validation?