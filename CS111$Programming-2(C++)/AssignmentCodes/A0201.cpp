#include <iostream>
#include <time.h>
using namespace std;

string *shuffleCards(string card_deck[]);

int main()
{

    string card_deck[52];
    string card_type[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    string card_nums[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int num_players = 6;

    string *shuffled_cards;
    int card_idx = 0;

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 13; j++)
        {
            card_deck[card_idx++] = card_type[i] + " - " + card_nums[j];
            // cout << card_type[i] + " - " + card_nums[j];
        }
    }

    shuffled_cards = shuffleCards(card_deck);

    // for (int i = 0; i < 52; i++)
    // {
    //     cout << shuffled_cards[i] << ", ";
    //     if ((i + 1) % 13 == 0)
    //     {
    //         cout << endl;
    //     }
    // }

    for (int i = 0; i < num_players; i++)
    {
        cout << "=========================================================================================================== " << endl;
        cout << "Player-" << i + 1 << ": ";
        for (int j = 0; j < 7; j++)
        {
            cout << card_deck[i * 7 + j] + ",  ";
        }
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------- " << endl;
    }

    return 0;
}

string *shuffleCards(string card_deck[])
{

    int shuffle_index;
    string temp;

    for (int i = 0; i < 52; i++)
    {
        shuffle_index = rand() % 52;
        temp = card_deck[i];
        card_deck[i] = card_deck[shuffle_index];
        card_deck[shuffle_index] = temp;
    }

    return card_deck;
}