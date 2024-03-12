#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
    cout << endl;
}

char checkWinner(const vector<vector<char>> &board)
{

    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));

    int row, col;
    char currentPlayer = 'X';

    for (int moves = 0; moves < 9; ++moves)
    {

        printBoard(board);

        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        {
            cout << "Invalid move! Try again." << endl;
            --moves;
            continue;
        }

        board[row][col] = currentPlayer;

        char winner = checkWinner(board);
        if (winner != ' ')
        {
            printBoard(board);
            cout << "Player " << winner << " wins!" << endl;
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    cout << "It's a draw!" << endl;

    return 0;
}
