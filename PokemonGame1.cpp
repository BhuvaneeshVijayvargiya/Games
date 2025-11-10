#include <iostream>
using namespace std;

struct Move
{
    string move_name;
    int move_power;
};

class Pokemon
{
public:
    string name = "Defaultimon";
    int speed = 50;
    int hp = 100;
    int attack = 10;
    int defense = 10;
    Move moves[4];
};

Pokemon create()
{
    Pokemon pokemon;

    cout << "Enter pokemon Name: \n";
    getline(cin, pokemon.name);
    cout << "\n";

    cout << "Enter its Speed: \n";
    cin >> pokemon.speed;
    cout << "\n";

    cout << "Enter its HP: \n";
    cin >> pokemon.hp;
    cout << "\n";

    cout << "Enter its Attack Stats: \n";
    cin >> pokemon.attack;
    cout << "\n";

    cout << "Enter it's Defense Stats: \n";
    cin >> pokemon.defense;
    cin.ignore();
    cout << "\n";

    cout << "Enter its moves: \n \n";
    for (int i = 0; i < 4; i++)
    {
        cout << "move " << i + 1 << "\n";
        cout << "Enter Move Name: \n";
        getline(cin, pokemon.moves[i].move_name);
        cout << "Enter Move Power: \n";
        cin >> pokemon.moves[i].move_power;
        cin.ignore();
        cout << "\n";
    }

    return pokemon;
}

int speed_test(Pokemon pokemon1, Pokemon pokemon2)
{
    if (pokemon1.speed < pokemon2.speed)
    {
        cout << pokemon2.name << " goes first \n\n";
        return 2;
    }
    else
    {
        cout << pokemon1.name << " goes first \n\n";
        return 1;
    }
}

void display(Pokemon POKEMON)
{
    cout << "  Name: " << POKEMON.name << endl;
    cout << "  Hp: " << POKEMON.hp << endl;
    cout << "  Speed: " << POKEMON.speed << endl;
    cout << "  Attack Stats: " << POKEMON.attack << endl;
    cout << "  Defense Stats: " << POKEMON.defense << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "  Move " << i + 1 << " : \n";
        cout << "     Move Name: " << POKEMON.moves[i].move_name << endl;
        cout << "     Move Power: " << POKEMON.moves[i].move_power << endl;
    }
}

Pokemon battle(Pokemon faster, Pokemon slower)
{
    int turn = 0;

    bool faster_fainted = false;
    bool slower_fainted = false;
    int move_num;
    int damage;

    while (faster_fainted == false && slower_fainted == false)
    {
        if (turn % 2 == 0)
        {
            cout << "Choose the move number: \n";
            cin >> move_num;
            damage = faster.moves[move_num - 1].move_power * faster.attack / slower.defense;
            slower.hp -= damage;

            cout << "Damage done: " << damage << endl;

            if (slower.hp > 0)
            {
                cout << "Health remaining: " << slower.hp << endl
                     << endl;
            }
            else
            {
                cout << "Pokemon fainted \n\n";
            }

            turn++;
        }
        else
        {
            cout << "Choose the move number: \n";
            cin >> move_num;
            damage = slower.moves[move_num - 1].move_power * slower.attack / faster.defense;
            faster.hp -= damage;

            cout << "Damage done: " << damage << endl;

            if (faster.hp > 0)
            {
                cout << "Health remaining: " << faster.hp << endl
                     << endl;
            }
            else
            {
                cout << "Pokemon fainted \n\n";
            }

            turn++;
        }

        if (faster.hp <= 0)
        {
            faster_fainted = true;
            return slower;
        }

        if (slower.hp <= 0)
        {
            slower_fainted = true;
            return faster;
        }
    }
}

int main()
{

    bool play = true;

    while (play == true)
    {

        cout << "\n\n=======CREATION PHASE=======\n\n\n\nCreate 2 Pokemons \n\n\n";

        Pokemon pokemon1, pokemon2;

        int create1;
        cout << "Enter 64 to create Pokemon 1 manually, or any other number to use default pokemon \n";
        cin >> create1;
        cin.ignore();
        if (create1 == 64)
        {
            cout << "Create Pokemon 1 \n\n";
            pokemon1 = create();
        }
        else
        {
            cout << "Using Default Pokemon \n\n";
            for (int i = 0; i < 4; i++)
            {
                pokemon1.moves[i].move_name = string("move") + to_string(i + 1);
                pokemon1.moves[i].move_power = 10 * (i + 1);
            }
        }

        int create2;
        cout << "Enter 64 to create Pokemon 2 manually, or any other number to use default pokemon \n";
        cin >> create2;
        cin.ignore();
        if (create2 == 64)
        {
            cout << "Create Pokemon 2 \n\n";
            pokemon2 = create();
        }
        else
        {
            cout << "Using Default Pokemon \n\n\n\n";
            for (int i = 0; i < 4; i++)
            {
                pokemon2.moves[i].move_name = string("move") + to_string(i + 1);
                pokemon2.moves[i].move_power = 10 * (i + 1);
            }
        }

        cout << "Pokemon 1 => \n";
        display(pokemon1);
        cout << "\nPokemon 2 => \n";
        display(pokemon2);

        cout << "\n\n\n\n=======BATTLE PHASE======= \n\n\n\n\n";

        int faster_pokemon = speed_test(pokemon1, pokemon2);

        Pokemon winner;

        if (faster_pokemon == 2)
        {
            winner = battle(pokemon2, pokemon1);
        }

        else
        {
            winner = battle(pokemon1, pokemon2);
        }

        cout << winner.name << " wins the game. \n\n";

        char replay;
        cout << "do you wanna play again (Enter 'n' to stop): ";
        cin >> replay;
        if (replay == 'n')
        {
            play = false;
        }
    }

    return 0;
}