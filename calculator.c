#include <stdio.h>
#include <stdlib.h>

// Function declarations
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    int choice;
    float num1, num2, result;

    while (1) {
        printf("\n--- C Calculator ---\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        // Validate choice
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);

        switch (choice) {
            case 1: result = add(num1, num2); break;
            case 2: result = subtract(num1, num2); break;
            case 3: result = multiply(num1, num2); break;
            case 4: result = divide(num1, num2); break;
        }

        printf("Result = %.2f\n", result);
    }

    return 0;
}
