#include <iostream>
using namespace std;

void displayBoard(char board[])
{
    cout << "\n";
    cout << "        TIC TAC TOE\n";
    cout << "    -----------------\n";
    cout << "       " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "    ----|---|----\n";
    cout << "       " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "    ----|---|----\n";
    cout << "       " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "    -----------------\n";
}

bool checkWin(char board[], char player)
{
    int win[8][3] =
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++)
    {
        if (board[win[i][0]] == player &&
            board[win[i][1]] == player &&
            board[win[i][2]] == player)
        {
            return true;
        }
    }

    return false;
}

bool checkDraw(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char playAgain;
    int scoreX = 0;
    int scoreO = 0;
    int draws = 0;

    cout << "=================================\n";
    cout << "       TIC TAC TOE GAME\n";
    cout << "=================================\n";

    do
    {
        char board[9] = {'1','2','3','4','5','6','7','8','9'};
        char player = 'X';
        int position;

        cout << "\nPlayer X : X";
        cout << "\nPlayer O : O\n";

        while (true)
        {
            displayBoard(board);

            cout << "\nPlayer " << player << ", choose a position (1-9): ";
            cin >> position;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number from 1 to 9.\n";
                continue;
            }

            if (position < 1 || position > 9)
            {
                cout << "Invalid position! Choose between 1 and 9.\n";
                continue;
            }

            if (board[position - 1] == 'X' ||
                board[position - 1] == 'O')
            {
                cout << "That position is already occupied!\n";
                continue;
            }

            board[position - 1] = player;

            if (checkWin(board, player))
            {
                displayBoard(board);
                cout << "\n*** Player " << player << " WINS! ***\n";

                if (player == 'X')
                    scoreX++;
                else
                    scoreO++;

                break;
            }

            if (checkDraw(board))
            {
                displayBoard(board);
                cout << "\n*** GAME DRAW! ***\n";
                draws++;
                break;
            }

            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }

        cout << "\n=================================\n";
        cout << "             SCORE\n";
        cout << "=================================\n";
        cout << "Player X : " << scoreX << "\n";
        cout << "Player O : " << scoreO << "\n";
        cout << "Draws    : " << draws << "\n";
        cout << "=================================\n";

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\n=================================\n";
    cout << "       THANKS FOR PLAYING!\n";
    cout << "=================================\n";

    return 0;
}
