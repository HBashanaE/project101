#include <iostream>
#include <iomanip>

void printBoard(const std::vector<std::vector<std::string>> &board)
{
    // clear the console
    std::cout << "\033[2J"; // clear the console

    std::cout << ".---.---.---." << std::endl;
    for (const auto &row : board)
    {
        std::cout << "| " << row[0] << " | " << row[1] << " | " << row[2] << " |" << std::endl;
        std::cout << ".---.---.---." << std::endl;
    }
}

int main()
{
    std::vector<std::vector<std::string>> board(3, std::vector<std::string>(3, " "));
    printBoard(board);

    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::cout << "Enter q to quit: " << std::endl;
    std::string userInput;
    while (true)
    {
        std::cout << "Player 1 (X) turn." << std::endl;
        std::cout << "Enter your move (row and column) or 'q' to quit: ";
        std::cin >> userInput;
        if (userInput == "q")
        {
            break;
        }
        int row, col;
        try
        {
            row = std::stoi(userInput.substr(0, 1));
            col = std::stoi(userInput.substr(1, 1));

            if (row < 0 || row > 2 || col < 0 || col > 2)
            {
                std::cout << "Invalid input. Row and column must be between 0 and 2." << std::endl;
                continue;
            }

            if (board[row][col] != " ")
            {
                std::cout << "Invalid move. Cell is already occupied." << std::endl;
                continue;
            }

            board[row][col] = "X";
            printBoard(board);
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Invalid input. Please enter row and column as numbers." << std::endl;
        }

        std::cout << "Player 2 (O) turn." << std::endl;
        std::cout << "Enter your move (row and column) or 'q' to quit: ";
        std::cin >> userInput;
        if (userInput == "q")
        {
            break;
        }
        try
        {
            row = std::stoi(userInput.substr(0, 1));
            col = std::stoi(userInput.substr(1, 1));

            if (row < 0 || row > 2 || col < 0 || col > 2)
            {
                std::cout << "Invalid input. Row and column must be between 0 and 2." << std::endl;
                continue;
            }

            if (board[row][col] != " ")
            {
                std::cout << "Invalid move. Cell is already occupied." << std::endl;
                continue;
            }
            board[row][col] = "O";
            printBoard(board);
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Invalid input. Please enter row and column as numbers." << std::endl;
        }
    }

    return 0;
}
