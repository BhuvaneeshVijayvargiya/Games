#include <iostream>
using namespace std;

const int H = 9, W = 15;

char baseMaze[H][W + 1] = {
    "###############",
    "#     #       #",
    "# #####  B    #",
    "# #   #       #",
    "# #   ####### #",
    "# #           #",
    "# ###B### ### #",
    "#       #    E#",
    "###############"};

char toggledMaze[H][W + 1] = {
    "###############",
    "#     #       #",
    "# #####  B    #",
    "# #   #       #",
    "# #   ####### #",
    "# #   ### #   #",
    "# ###B### ### #",
    "#       #    E#",
    "###############"};

char maze[H][W + 1];
bool isToggled = false;

int px = 1, py = 1;

void loadMaze(bool toggled)
{
    for (int r = 0; r < H; r++)
        for (int c = 0; c < W; c++)
            maze[r][c] = toggled ? toggledMaze[r][c] : baseMaze[r][c];

    maze[px][py] = 'P';
}

void printMaze()
{
    for (int r = 0; r < H; r++)
        cout << maze[r] << endl;
}

bool canMove(int r, int c)
{
    return (maze[r][c] != '#');
}

int main()
{
    loadMaze(false);

    cout << "===== TIME REWIND MAZE =====\n";
    cout << "Move with W A S D\n";
    cout << "Step on buttons (B) to change the maze\n";
    cout << "Press R to REWIND the maze (but YOU stay where you are)\n\n";

    while (true)
    {
        printMaze();
        cout << "Move: ";

        char input;
        cin >> input;

        int nx = px, ny = py;

        if (input == 'w')
            nx--;
        else if (input == 's')
            nx++;
        else if (input == 'a')
            ny--;
        else if (input == 'd')
            ny++;

        else if (input == 'r')
        {
            cout << "\nTime Rewound! Maze restored.\n";
            isToggled = false;
            loadMaze(false);
            continue;
        }
        else
        {
            cout << "Invalid key.\n";
            continue;
        }

        if (!canMove(nx, ny))
        {
            cout << "You hit a wall!\n";
            continue;
        }

        maze[px][py] = ' ';
        px = nx;
        py = ny;

        if (maze[px][py] == 'B')
        {
            cout << "\nButton pressed! The maze shifts...\n";
            isToggled = true;
            loadMaze(true);
            continue;
        }

        if (maze[px][py] == 'E')
        {
            cout << "\n🎉 You reached the exit! You win!\n";
            break;
        }

        maze[px][py] = 'P';
    }

    cout << "Game Over.\n";
    return 0;
}
