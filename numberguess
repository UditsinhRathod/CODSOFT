#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
    int secretNumber = rand() % 100 + 1;
    int guess = 0;

    cout << "Welcome to my Guess the Number Game!" << endl;
    cout << "I've picked a number between 1 and 100. Think you can find it?" << endl;

    while (guess != secretNumber) {
        cout << "Take a guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Oops! That's a bit too high. Give it another go!" << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! You can do better. Try again!" << endl;
        } else {
            cout << "You got it! The number was indeed " << secretNumber << ". Well done!" << endl;
        }
    }

    return 0;
}
