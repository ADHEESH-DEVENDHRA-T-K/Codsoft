#include <iostream>

using namespace std;

int main() {
    char op;
    float num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error! Division by zero." << endl;
            } else {
                cout << "Result: " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Error! Invalid operator." << endl;
            break;
    }

    return 0;
}