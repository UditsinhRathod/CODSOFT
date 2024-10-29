#include <iostream>

using namespace std;

int main() {
    double firstNumber, secondNumber;
    char op;

    cout << "Welcome to the simple calculator" << endl;
    cout << "Enter your first number: ";
    cin >> firstNumber;
    cout << "Now enter your second number: ";
    cin >> secondNumber;
    cout << "Pick an operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+':
            cout << "Here's what I got: " << firstNumber << " + " << secondNumber << " = " << (firstNumber + secondNumber) << endl;
            break;
        case '-':
            cout << "Here's what I got: " << firstNumber << " - " << secondNumber << " = " << (firstNumber - secondNumber) << endl;
            break;
        case '*':
            cout << "Here's what I got: " << firstNumber << " * " << secondNumber << " = " << (firstNumber * secondNumber) << endl;
            break;
        case '/':
            if (secondNumber != 0) {
                cout << "Here's what I got: " << firstNumber << " / " << secondNumber << " = " << (firstNumber / secondNumber) << endl;
            } else {
                cout << "Oops! Can't divide by zero." << endl;
            }
            break;
        default:
            cout << "Hmm... I didn't understand that operation." << endl;
    }

    return 0;
}
