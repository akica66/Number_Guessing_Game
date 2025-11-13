// Guessing_Number_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <string>  // For std::string
#include <limits> 

int main() {
	std::srand(std::time(0));
    char play_again = 'y';
        while (play_again == 'y' || play_again == 'Y') {

            int computer_choice = (std::rand() % 100) + 1;
            int user_choice = 0;
            int guess_count = 0;

            std::cout << "--------------------------------\n";
            std::cout << "       NUMBER GUESSING GAME    \n";
            std::cout << "-------------------------------\n";
            std::cout << "Enter your choice:\n";
            std::cout << "Selection: ";

            //runs until the number is not guessed != - not equal to the number thats supposed to be guessed
            while (user_choice != computer_choice) {
                guess_count++;

                std::cout << "Guess #" << guess_count << ": ";

                if (!(std::cin >> user_choice)) {
                    std::cout << "Invalid input type. Please enter a number.\\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    guess_count--; // Don't count invalid input as a guess
                    continue;
                }


                if (user_choice < 1 || user_choice > 100) {
                    std::cout << "Invalid selection (" << user_choice << "). Please choose 1, 2, or 3.\\n";
                    guess_count--;
                    continue; // Go back to the start of the while loop
                }

                if (user_choice > computer_choice) {
                    std::cout << "Too High! Guess lower.\n";
                }
                else if (user_choice < computer_choice) {
                    std::cout << "Too Low! Guess higher.\n";
                }
            }

            std::cout << "\n================================\n"; // <--- NEW/MODIFIED SUCCESS OUTPUT
            std::cout << "  VICTORY! The number was " << computer_choice
                << ". You found it in " << guess_count << " tries!\n";
            std::cout << "================================\n";

            // Ask to play again
            std::cout << "Play another game? (y/n): ";
            std::cin >> play_again;

            // Clear the input buffer before the outer loop continues
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    std::cout << "Thanks for playing! Goodbye.\n";
    return 0;
}
