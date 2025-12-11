#include <iostream>
#include <stdexcept>
using namespace std;

class Calculator {
private:
    float a, b;

public:
    Calculator() {
        a = b = 0;
    }

    void getInput() {
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
    }

    float add() { return a + b; }
    float subtract() { return a - b; }
    float multiply() { return a * b; }

    float divide() {
        if (b == 0)
            throw runtime_error("Error: Divide by zero!");
        return a / b;
    }
};

int main() {
    Calculator calc;
    int choice;

    while (true) {
        cout << "\n--- C++ OOP Calculator ---\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice!\n";
            continue;
        }

        calc.getInput();

        try {
            switch (choice) {
                case 1: cout << "Result = " << calc.add() << endl; break;
                case 2: cout << "Result = " << calc.subtract() << endl; break;
                case 3: cout << "Result = " << calc.multiply() << endl; break;
                case 4: cout << "Result = " << calc.divide() << endl; break;
            }
        }
        catch (exception &e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
