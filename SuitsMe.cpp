//============================================================================
// Name        : SuitsMe.cpp
// Author      : Haojin Li
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Deck.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int num_discard(vector<string> discard_pile)
{
    int pile_top = discard_pile.size() - 1;
    string top_face = discard_pile[pile_top].substr(1,1);
    if(top_face == "1" || top_face == "2" || top_face == "3" || top_face == "4" || top_face == "5" || top_face == "6" || top_face == "7" || top_face == "8" || top_face == "9")
    {
        return 1;
    }
    else if((discard_pile[pile_top].substr(0,1) == "S" || discard_pile[pile_top].substr(0,1) == "C") && top_face == "A")
    {
        return 3;
    }
    else if((discard_pile[pile_top].substr(0,1) == "H" || discard_pile[pile_top].substr(0,1) == "D") && top_face == "A")
    {
        return 5;
    }
    else return 2;
}

void win_check(bool &winner,Player players[4])
{
    for(int i=0; i<4; ++i)
    {
        int maxsuit_num =0;
        string maxsuit = players[i].get_maxsuit();
        for(int j=0; j<players[i].hand.size(); ++j)
        {
            if(players[i].hand[j].substr(0,1) == maxsuit) maxsuit_num++;
        }
        if(maxsuit_num == players[i].hand.size() && maxsuit_num > 0)
        {
            cout<< "Winner is player "<<i+1<<"!";
            winner = true;
            break;
        }
    }
}

int main() {
    Player players[4];
    vector<string> discardPile;
    CardDeck deck;
    deck.shuffleDeck();
    bool winner = false;
    
    //Deal cards to players
    for(int i=0; i<4; ++i)
    {
        deck.dealCards(players[i],7);
    }
    
    //Start the Game
    while(1)
    {
        //Check for a winner
        win_check(winner,players);
        if(winner) break;
        
        int card_index;
        players[0].show_hand();
        cout<<"Which card would you like to pass? Enter the number:"<<endl;
        cin >>card_index;
        card_index--;
        
        players[0].passCard(players[1],card_index);
        players[1].auto_pass(players[2]);
        
        players[2].auto_pass(players[3]);
        players[3].auto_pass(players[0]);
        
        
        //Discarding Round----------------------------------------------------------------------------
        
        int discard_index;
        int temp_size;
        
        //Add random card if discard pile is empty
        if(discardPile.size() == 0)
        {
            string temp = deck.deck[deck.deck.size()-1];
            discardPile.push_back(temp);
            deck.deck.pop_back();
        }
        
        temp_size = num_discard(discardPile);
        for(int i=0; i<temp_size; ++i)
        {
            cout<<"Which card would you like to discard? Enter the number: "<<endl;
            cin >>discard_index;
            discard_index--;
            players[0].discard(discard_index, discardPile);
        }
        
        for(int i=1; i<4; ++i)
        {
            temp_size = num_discard(discardPile);
            
            for(int j=0; j<temp_size; ++j)
            {
                players[i].auto_discard(discardPile);
            }
            
        }
        
        
        //If deck runs out, add all discarded cards back in except the top card
        if(deck.deck.size() == 0)
        {
            for(int i=0; i<discardPile.size() - 2; ++i)
            {
                deck.deck.push_back(discardPile[i]);
                discardPile.erase(discardPile.begin() + i);
            }
        }
        else
        {
            for(int i=0; i<4; ++i)
            {
                deck.dealCards(players[i],1);
            }
        }
    }
    
    
}
