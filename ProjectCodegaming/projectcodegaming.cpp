#include <iostream>
#include <cstdlib>
#include  <ctime>

using namespace std;

int main()

{
    int option;
    int balance = 0;
    int round_balance = 0;
    int letter_bet = 0;
    int letter_guesses = 0;
    int number_guesses = 0;
    char letter_choice;
    char letter_answer;
    int number_choice;
    int number_mathches;
    int number_wins = 0;


    srand(time(NULL)); // send the random number generator

    do
    { // display menu
        cout << endl;
        cout << "Guess the letter Game" << endl;
        cout << "Guess the number Game" << endl;
        cout << "Exit" << endl;
        cout << endl;
        cout << "Please choose an option";
        cin >> option;

        switch (option)
        {
        case 1:
            // reset round balance
            round_balance = 0;

            // generate random letter
            letter_answer = rand() % 26 + 'A';

            //ask for uppercase or lowercase guess
            cout << "Are you guessing uppercase or lowercase? (U/L)";
            cin >> letter_choice;

            // check if guess is correct
            if ((letter_choice == 'U' && letter_choice < 'a') || (letter_choice == 'L' && letter_answer >= 'a'))
            {
                round_balance += 10;
                cout << "correct! You earned 10 points." << endl;
            }
            else
            {
                cout << "Sorry, that is incorrect. The answer was";
                if (letter_answer < 'a')
                    cout << "uppercase";
                else
                    cout << "lowercase ";
                cout << letter_answer << "." << endl;
            }
            // ask for number of guesses
            do
            {
                cout << "How many guesses do you want to make? (1-10)";
                cin >> letter_guesses;
            } while (letter_guesses < 1 || letter_guesses > 10);

            // play game
            for (int i = 0; i < letter_guesses; i++)
            {
                cout << "Guess #" << i + 1 << ": ";
                cin >> letter_bet;

                // check if guess is close
                if (abs(letter_answer - letter_bet) <= 2)
                {
                    cout << "Close, but not quite: You dont lose any points." << endl;
                }
                else
                {
                    round_balance = letter_bet;
                    cout << "Sorry, that is incorrect. Your balance is now" << round_balance << "." << endl;
                }

                // check if guess is correct
                if (letter_bet == letter_answer)
                {
                    round_balance += letter_bet * letter_guesses;
                    cout << "Congratulations! you earned " << letter_bet * letter_guesses << "points." << endl;

                    break;
                }
            }
            // display balance and update total balance
            cout << "Your balance is now" << round_balance << "." << endl;
            balance += round_balance;

            break;
        case 2: {
            int guess, wins = 0;
            bool game_over = false;
            srand(time(0)); // initialize random seed
            do {
                cout << "Enter a number in 1-50 inclusive:";
                cin >> guess;
                if (guess < 1 || guess > 50) {
                    cout << "Invalid input! please enter a number in 1-50 incluisive.\n";

                }
                int matches = 0;
                for (int i = 0; i < 25; i++) {
                    int num = rand() % 50 + 1; // generate a random number from 1 to 50
                    if (num == guess) {
                        matches++;
                    }
                }
                if (matches > 0) {
                    cout << guess << "appears on the list " << "time(s)./n";
                    wins++;
                }
                else {
                    cout << "Game Over!\n";
                    game_over = true;
                }
            } while (!game_over);
            cout << "Your number of wins:" << wins << endl;

            break;
        }
        case 3: {
            cout << "Ending the program . . ." << endl;
            break;
        }
        default: {
            cout << "Invalid input! Please enter 1,2, or 3." << endl;
            break;
        }
        }
        
 
   }
   while (true);
   {

   }
}