#include <iostream>
#include <iomanip>

void printBoard(const std::vector<std::vector<std::string>> &board)
{
    // clear the console
    std::cout << "\033[2J"; // clear the console

    std::cout << ".---.---.---." << std::endl;
    for (const std::vector<std::string> &row : board)
    {
        std::cout << "| " << row[0] << " | " << row[1] << " | " << row[2] << " |" << std::endl;
        std::cout << ".---.---.---." << std::endl;
    }
}

void playerInteraction(int turn, std::vector<std::vector<std::string>> &board)
{
    std::string userInput;

    std::cout << "Player " << turn % 2 + 1 << " (" << (turn % 2 == 0 ? "X" : "O") << ") turn." << std::endl;

    while (true)
    {
        std::cout << "Enter your move (row and column) or 'q' to quit: ";
        std::cin >> userInput;

        if (userInput == "q")
        {
            exit(0);
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

            board[row][col] = turn % 2 == 0 ? "X" : "O";
            printBoard(board);
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Invalid input. Please enter row and column as numbers." << std::endl;
        }
        break;
    }
}

void checkWinner(const std::vector<std::vector<std::string>> &board)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] != " " && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            std::cout << "Player " << (board[i][0] == "X" ? 1 : 2) << " wins!" << std::endl;
            exit(0);
        }
        if (board[0][i] != " " && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            std::cout << "Player " << (board[0][i] == "X" ? 1 : 2) << " wins!" << std::endl;
            exit(0);
        }
    }

    // Check diagonals
    if (board[0][0] != " " && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        std::cout << "Player " << (board[0][0] == "X" ? 1 : 2) << " wins!" << std::endl;
        exit(0);
    }
    if (board[0][2] != " " && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        std::cout << "Player " << (board[0][2] == "X" ? 1 : 2) << " wins!" << std::endl;
        exit(0);
    }
}

int main()
{
    std::vector<std::vector<std::string>> board(3, std::vector<std::string>(3, " "));
    printBoard(board);

    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::cout << "Enter q to quit: " << std::endl;
    std::string userInput;
    int turn = 9;
    while (turn--)
    {
        playerInteraction(turn, board);
        checkWinner(board);
    }

    std::cout << "Game over! It's a draw!" << std::endl;

    return 0;
}
