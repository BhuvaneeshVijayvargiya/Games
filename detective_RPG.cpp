#include <iostream>
using namespace std;

int main()
{
    cout << "=========================================\n";
    cout << "              DETECTIVE RPG\n";
    cout << "=========================================\n\n";

    cout << "You enter a small study room.\n";
    cout << "Someone sabotaged Dr. Renner's research\n";
    cout << "Find the clues and solve the mystery\n\n";

    bool foundNote = false;
    bool movedPainting = false;
    bool foundCode = false;
    bool openedSafe = false;
    bool solved = false;

    int choice;

    while (!solved)
    {
        cout << "\nWhat would you like to inspect\n";
        cout << "1. Desk\n";
        cout << "2. Painting\n";
        cout << "3. Bookshelf\n";
        cout << "4. Safe\n";
        cout << "5. Make final accusation\n";
        cout << "Enter choice: ";
        cin >> choice;

        cout << "\n";

        if (choice == 1)
        {
            if (!foundNote)
            {
                cout << "You open the desk drawer and find a torn note\n";
                cout << "It reads: 'The code begins with 42'\n";
                foundNote = true;
            }
            else
            {
                cout << "There's nothing else in the desk\n";
            }
        }

        else if (choice == 2)
        {
            if (!movedPainting)
            {
                cout << "You lift the painting from the wall\n";
                cout << "Behind it, there's a small scribble: '...19'.\n";
                movedPainting = true;
                foundCode = true;
            }
            else
            {
                cout << "The wall behind the painting is empty now\n";
            }
        }

        else if (choice == 3)
        {
            cout << "You inspect the bookshelf. Nothing stands out\n";
        }

        else if (choice == 4)
        {
            if (!foundCode)
            {
                cout << "The safe has a 4-digit lock\n";
                cout << "You don't know the full code yet\n";
            }
            else if (!openedSafe)
            {
                int entered;
                cout << "Enter the 4-digit code: ";
                cin >> entered;

                if (entered == 4219)
                {
                    cout << "\nThe safe clicks open!\n";
                    cout << "Inside is a USB drive containing the real lab logs\n";
                    openedSafe = true;
                }
                else
                {
                    cout << "Incorrect code\n";
                }
            }
            else
            {
                cout << "The safe is already open\n";
            }
        }

        else if (choice == 5)
        {
            if (!openedSafe)
            {
                cout << "You don't have enough evidence yet\n";
            }
            else
            {
                int acc;
                cout << "Who sabotaged the research?\n";
                cout << "1. Dr. Renner\n";
                cout << "2. His assistant, Mira\n";
                cout << "3. A random intruder\n";
                cout << "Enter your accusation: ";
                cin >> acc;

                if (acc == 1)
                {
                    cout << "\nCorrect!\n";
                    cout << "The USB logs reveal Dr. Renner faked the sabotage.\n";
                    cout << "Case solved.\n";
                    solved = true;
                }
                else
                {
                    cout << "\nThat's incorrect\n";
                    cout << "Review the clues and try again\n";
                }
            }
        }

        else
        {
            cout << "Invalid choice\n";
        }
    }

    cout << "\nThank you for playing!!!!\n";
    return 0;
}
