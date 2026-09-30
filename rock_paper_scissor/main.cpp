#include <iostream>
#include <random>

bool validateUserInput(int userChoice)
{
    if (userChoice < 1 || userChoice > 3)
    {
        std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
        return false; // Return false for invalid choice
    }

    // check if user input is integer
    if (std::cin.fail())
    {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        return false; // Return false for invalid input
    }

    return true; // Valid input
}

int chooseRandom()
{
    // randomly choose 1, 2 or 3
    std::random_device rd; // obtain a random number from hardware

    std::mt19937 gen(rd()); // seed the generator

    std::uniform_int_distribution<int> distr(1, 3); // define the range

    return distr(gen);
}

int main()
{
    std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
    std::cout << "Enter q to quit: " << std::endl;
    while (true)
    {
        int machineChoice = chooseRandom();
        int userChoiceInt;
        std::string userChoice;
        std::cout << "Enter your choice (rock: 1, paper: 2, scissors: 3): ";
        std::cin >> userChoice;

        if (userChoice == "q")
        {
            std::cout << "Thanks for playing!" << std::endl;
            break;
        }

        try
        {
            userChoiceInt = std::stoi(userChoice);      // Convert string to integer
            userChoice = std::to_string(userChoiceInt); // Convert back to string for validation
        }
        catch (const std::invalid_argument &)
        {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            continue; // Skip the rest of the loop and prompt again
        }

        // Validate user input
        if (!validateUserInput(userChoiceInt))
        {
            return 1; // Exit with error code
        }

        // print winner
        if (machineChoice == userChoiceInt)
        {
            std::cout << "It's a tie. Try again" << std::endl;
            continue; // Skip the rest of the loop and prompt again
        }
        if ((userChoiceInt == 1 && machineChoice == 3) || (userChoiceInt == 2 && machineChoice == 1) || (userChoiceInt == 3 && machineChoice == 2))
        {
            std::cout << "User wins!" << std::endl;
        }
        else
        {
            std::cout << "Machine wins!" << std::endl;
        }
    }

    return 0;
}
