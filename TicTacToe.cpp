#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void display_board()
{
    cout << "\n " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n\n";
}

void clear(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void place_marker(int box, char marker)
{
    if (box == 1)
    {
        board[0][0] = marker;
    }
    else if (box == 2)
    {
        board[0][1] = marker;
    }
    else if (box == 3)
    {
        board[0][2] = marker;
    }
    else if (box == 4)
    {
        board[1][0] = marker;
    }
    else if (box == 5)
    {
        board[1][1] = marker;
    }
    else if (box == 6)
    {
        board[1][2] = marker;
    }
    else if (box == 7)
    {
        board[2][0] = marker;
    }
    else if (box == 8)
    {
        board[2][1] = marker;
    }
    else if (box == 9)
    {
        board[2][2] = marker;
    }
}

char check_result()
{
    char wining_marker = 'n';

    for (int i = 0; i < 3; i++)
    {

        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            wining_marker = board[i][1];
        }
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            wining_marker = board[1][i];
        }
        else if (board[1][1] == board[0][0] && board[1][1] == board[2][2] ||
                 board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            wining_marker = board[1][1];
        }

        if (wining_marker != 'n')
        {
            return wining_marker;
        }
    }
    return ' ';
}

int main()
{

    cout << "\nFormat of the board: " << endl;
    display_board();

    char marker;
    bool play = true;
    char replay;

    while (play == true)
    {

        char marker1, marker2;
        cout << "Player 1 chooose your marker (O/X): ";
        cin >> marker1;
        cout << "\n";

        if (marker1 == 'O')
        {
            marker2 = 'X';
        }
        else
        {
            marker1 = 'X';
            marker2 = 'O';
        }

        int turn = 0;
        int box = 0;
        clear(board);

        while (turn < 9)
        {

            if (turn % 2 == 0)
            {
                marker = marker1;
                cout << "Player 1's turn. Choose your box: ";
            }

            else
            {
                marker = marker2;
                cout << "Player 2's turn. Choose your box: ";
            }

            cin >> box;
            place_marker(box, marker);
            box = 0;
            marker = ' ';

            turn++;
            display_board();
            cout << "\n";

            char wining_marker = check_result();
            if (wining_marker == marker1)
            {
                cout << "Player 1 is the Winner \n\n";
                break;
            }
            else if (wining_marker == marker2)
            {
                cout << "Player 2 is the Winner \n\n";
                break;
            }
        }

        cout << "Press 'Y' if you wanna play again ";
        cin >> replay;
        if (replay != 'Y')
        {
            play = false;
            cout << "\nThank You for playing\n";
        }
    }

    return 0;
}