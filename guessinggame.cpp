#include <iostream>
#include <cstdlib> //for rand and srand
#include <time.h>
#include <cmath>
using namespace std;

void guessedNumber(int guess, int number) {
    if(guess > number) {
        cout << "Too high!\n";
    }
    else if(guess < number) {
        cout << "Too low!\n";
    }
}

int main() {
    srand(time(NULL));
    int number = 0;
    number = rand() % 100 + 1;
    int guess = 0;
    int count = 0;
    float compGuess = 0;
    float prevGuess = 0;
    int randNum, a, ans = 0;
    int lowerLimit = 1;
    int upperLimit = 100;

    cout << "Do you want to guess the number or let the computer guess?\n";
    cout << "Press 1 for you to guess and 2 for the computer to guess\n";
    cin >> a;
    
    if(a == 1) {
        cout << "Okay! Guess the number between 1-100.\n"; 
        while(guess != number){
            cin >> guess;
            guessedNumber(guess, number);
            count++;
        }
        cout << "Congratulations! You guessed the correct number in " << count << " tries!\n";
    }
    else if(a == 2) {
        cout << "Press 1 if it is too high, press 2 if it is too low, or press 3 when the computer gusses right.\n";
        do {
            randNum = (lowerLimit + upperLimit + 1) / 2;
            cout << "The computer guesses " << randNum << endl;
            cin >> ans;
            
            if (ans == 1) {
                upperLimit = randNum - 1;
            }
            else if (ans == 2) {
                lowerLimit = randNum + 1;
            }
            else if (ans == 3) {
                cout << "Yay!\n";
            }
            else {
                cout << "Sorry the computer did not recognize the input.\n";
                cout << "Please try again\n";
                continue;
            }
        } while (ans != 3);

    }
}
