#include<iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    
    
    srand(time(0));

    
    int randomNumber = rand() % 100 + 1;

    
    int guess;
    int attempts = 0;

    
    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have chosen a number between 1 and 100. Can you guess it?\n\n";

    
    do
    {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        
        if (guess == randomNumber)
        {
            std::cout << "Congratulations! You guessed the number " << randomNumber << " correctly!\n";
            std::cout << "It took you " << attempts << " attempts.\n";
        }
        else if (guess < randomNumber)
        {
            std::cout << "Too low! Try again.\n";
        }
        else
        {
            std::cout << "Too high! Try again.\n";
        }
    } while (guess != randomNumber);

    return 0;
}