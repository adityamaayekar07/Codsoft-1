#include <iostream>
#include <cstdlib>   // For std::rand() and std::srand()
#include <ctime>     // For std::time()
#include <climits>   // For INT_MAX

int main() {
    // Seed the random number generator
    std::srand(std::time(0)); 

    // Define the range for the random number
    const int MIN = 1;
    const int MAX = 100;
    
    // Generate a random number between MIN and MAX
    int targetNumber = std::rand() % (MAX - MIN + 1) + MIN;
    
    int guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between " << MIN << " and " << MAX << "." << std::endl;

    // Game loop
    while (guess != targetNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        
        // Input validation
        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(INT_MAX, '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        attempts++;

        if (guess < targetNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > targetNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    }

    return 0;
}
