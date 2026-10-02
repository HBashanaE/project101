#include <iostream>
#include <array>
#include <string>
#include <stdexcept>

using Board = std::array<std::array<char, 3>, 3>;

void printBoard(const Board &board)
{
    // clear the console
    std::cout << "\033[2J\033[H";

    std::cout << ".---.---.---." << std::endl;
    for (const std::array<char, 3> &row : board)
    {
        std::cout << "| " << row[0] << " | " << row[1] << " | " << row[2] << " |" << std::endl;
        std::cout << ".---.---.---." << std::endl;
    }
}

bool playerInteraction(char player, Board &board)
{
    std::string userInput;

    std::cout << "Player " << player << " turn." << std::endl;

    while (true)
    {
        std::cout << "Enter your move (row and column) or 'q' to quit: ";
        std::cin >> userInput;

        if (userInput == "q")
        {
            return false;
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

            if (board[row][col] != ' ')
            {
                std::cout << "Invalid move. Cell is already occupied." << std::endl;
                continue;
            }

            board[row][col] = player;
            printBoard(board);
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Invalid input. Please enter row and column as numbers." << std::endl;
            continue;
        }
        break;
    }
    return true;
}

bool checkWinner(const Board &board)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Check diagonals
    return (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||

           (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]);
}

int main()
{
    Board board = {{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}};
    printBoard(board);

    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::cout << "Enter q to quit: " << std::endl;
    std::string userInput;
    int turn = 9;
    while (turn--)
    {
        char player = turn % 2 == 0 ? 'X' : 'O';
        if (!playerInteraction(player, board))
        {
            exit(0);
        }
        if (checkWinner(board))
        {
            std::cout << "Game over! Player " << player << " wins!" << std::endl;
            exit(0);
        }
    }

    std::cout << "Game over! It's a draw!" << std::endl;

    return 0;
}
