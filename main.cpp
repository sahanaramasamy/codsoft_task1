#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

// Function to display game title
void displayTitle() {
    cout << "\n*************************************\n";
    cout << "        NUMBER GUESSING GAME\n";
    cout << "*************************************\n";
}

// Function for selection of difficulty level
int chooseDifficulty() {

    int choice,maxRange;

    cout << "\nSelect Difficulty Level:\n";
    cout << "1. Easy   (1 - 50)\n";
    cout << "2. Medium (1 - 100)\n";
    cout << "3. Hard   (1 - 500)\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice) {

        case 1:
            maxRange = 50;
            break;

        case 2:
            maxRange = 100;
            break;

        case 3:
            maxRange = 500;
            break;

        default:
            cout << "\nInvalid choice! Default difficulty level set to Medium.\n";
            maxRange = 100;
    }

    return maxRange;
}


int main() {

    srand(time(0));

    char playAgain;

    do {

        displayTitle();

        int maxRange = chooseDifficulty();

        int secretNumber = rand() % maxRange + 1;

        int userGuess = 0;
        int attempts = 0;

        cout << "\nA random number has been generated between 1 and "
             << maxRange << ".\n";

        cout << "Try to guess the correct number.\n";

        while(userGuess != secretNumber) {

            cout << "\nEnter your guess: ";

            while(!(cin >> userGuess)) {

                cout << "Invalid input! Please enter a numeric value: ";

                cin.clear();

            }

            attempts++;

            if(userGuess > secretNumber) {

                cout << "Too High! Please try a smaller number.\n";
            }

            else if(userGuess < secretNumber) {

                cout << "Too Low! Please try a larger number.\n";
            }

            else {

                cout << "Congratulations! You guessed it.\n";

                cout << "Total Attempts : " << attempts << endl;

            }

            // Hint Feature
            if(attempts == 3 && userGuess != secretNumber) {

                cout << "\nHint: ";

                if(secretNumber % 2 == 0)
                    cout << "The secret number is EVEN.\n";

                else
                    cout << "The secret number is ODD.\n";
            }
        }

        //Option for Replay 
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\n************************************\n";
    cout << " Thank You for Playing the Game!\n";
    cout << "*************************************\n";

    return 0;
}