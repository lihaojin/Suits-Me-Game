/*
 * Deck.h
 *
 *  Created on: Jul 22, 2018
 *      Author: Haojin Li
 */

#ifndef DECK_H_
#define DECK_H_
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "Player.h"

class CardDeck
{
private:
    std::string faces[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    std::string suits[4] = {"H","D","C","S"};
    
public:
    
    std::vector<std::string> deck = generateDeck(faces,suits);
    //std::vector<std::string> discardPile;
    
    std::vector<std::string> generateDeck(std::string faces[13],std::string suits[4])
    {
        std::vector<std::string> cards;
        for(int i=0; i<13; ++i){
            for(int j=0; j<4; ++j){
                std::string card = suits[j] + faces[i];
                cards.push_back(card);
            }
        }
        return cards;
    }
    
    void shuffleDeck()
    {
        std::srand(std::time(0));
        std::random_shuffle(deck.begin(),deck.end());
    }
    
    void dealCards(Player& P, int num_cards)
    {
        for(int i=0; i<num_cards; ++i)
        {
            std::string temp = deck[deck.size()-1];
            P.hand.push_back(temp);
            deck.pop_back();
        }
    }
    
    void show_discard(std::vector<std::string> &discardPile)
    {
        for(int i=0; i<discardPile.size(); ++i)
        {
            std::cout<<"("<<i+1<<") "<<discardPile[i]<<" ";
        }
        std::cout<<"\n";
    }
};



#endif /* DECK_H_ */

