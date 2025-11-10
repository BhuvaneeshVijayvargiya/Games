#include <iostream>
using namespace std;

int main()
{
    cout << "=========================================\n";
    cout << "                ROOM 12\n";
    cout << "=========================================\n\n";

    cout << "You are Detective Jules Verne.\n";
    cout << "A mysterious incident occurred inside Room 12 of the Times New Hotel.\n";
    cout << "A guest, Elias Vorn, vanished without a trace.\n";
    cout << "Your job: Explore the room and uncover what truly happened.\n\n";

    bool checkedDesk = false;
    bool checkedMirror = false;
    bool foundKey = false;
    bool openedBox = false;
    bool readDiary = false;
    bool foundCodeHint = false;
    bool solved = false;
    int choice;

    while (!solved)
    {
        cout << "\nWhat would you like to inspect?\n";
        cout << "1. Desk\n";
        cout << "2. Miror\n";
        cout << "3. Bedside table\n";
        cout << "4. Floorboard\n";
        cout << "5. Locked box\n";
        cout << "6. Final theory\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << "\n";

        if (choice == 1)
        {
            if (!checkedDesk)
            {
                cout << "The desk is old and dusty. A single drawer is locked.\n";
                cout << "There's a note on top: 'Truth hides beneath reflection.'\n";
                checkedDesk = true;
            }
            else
            {
                cout << "Nothing new on the desk.\n";
            }
        }

        else if (choice == 2)
        {
            if (!checkedMirror)
            {
                cout << "You examine the tall mirror.\n";
                cout << "Up close, you notice fingerprints around the frame.\n";
                cout << "You push it slightly and a small metal key drops out.\n";
                foundKey = true;
                checkedMirror = true;
            }
            else
            {
                cout << "Nothing new around the mirror.\n";
            }
        }

        else if (choice == 3)
        {
            if (!foundCodeHint)
            {
                cout << "Inside the bedside drawer, you find a torn diary page.\n";
                cout << "It reads: 'The shadows whisper in numbers: 7... 3...'\n";
                foundCodeHint = true;
            }
            else
            {
                cout << "Nothing else here.\n";
            }
        }

        else if (choice == 4)
        {
            if (!readDiary)
            {
                cout << "You kneel and tap the wooden floorboards.\n";
                cout << "One of them sounds hollow.\n";
                cout << "You lift it and find a hidden diary.\n";
                cout << "Inside: 'I fear someone is watching me. If I disappear, the answer is in the box.'\n";
                cout << "Another line: 'The code ends with 1.'\n";
                readDiary = true;
            }
            else
            {
                cout << "Nothing else here.\n";
            }
        }

        else if (choice == 5)
        {
            if (!foundKey)
            {
                cout << "A small metal box lies under the bed.\n";
                cout << "It's locked. You need a key.\n";
            }
            else if (!openedBox)
            {
                int code;
                cout << "You use the key. The box needs a 3-digit code.\n";
                cout << "Enter the code: ";
                cin >> code;

                if (code == 731)
                {
                    cout << "\nThe box clicks open.\n";
                    cout << "Inside is a recording device.\n";
                    cout << "You play it:\n";
                    cout << "'If you're hearing this, it means I'm gone.\n";
                    cout << "I discovered a secret organization within the hotel...'\n";
                    cout << "'They took me when I refused to stay silent.'\n";
                    cout << "'Find the manager. He knows everything.'\n";
                    openedBox = true;
                }
                else
                {
                    cout << "Incorrect code.\n";
                }
            }
            else
            {
                cout << "The box is already open.\n";
            }
        }

        else if (choice == 6)
        {
            if (!openedBox)
            {
                cout << "You don’t have enough evidence yet.\n";
                continue;
            }

            cout << "Who is responsible for Elias Vorn's disappearance?\n";
            cout << "1. A random intruder\n";
            cout << "2. The hotel manager\n";
            cout << "3. Elias staged his own disappearance\n";
            cout << "Enter your theory: ";
            int acc;
            cin >> acc;

            if (acc == 2)
            {
                cout << "\nCorrect.\n";
                cout << "The clues all point to a hidden operation run by the manager.\n";
                cout << "You solved the case.\n";
                solved = true;
            }
            else if (acc == 3)
            {
                cout << "\nPartially correct—but missing details.\n";
                cout << "Elias did NOT stage the disappearance. He was taken.\n";
            }
            else
            {
                cout << "\nIncorrect.\n";
                cout << "Review your clues and try again.\n";
            }
        }

        else
        {
            cout << "Invalid choice.\n";
        }
    }

    cout << "\nThank you for playing ROOM 12.\n";
    return 0;
}
