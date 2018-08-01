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
	int pile_top = discard_pile.size() - 1
	string top_face = discard_pile[pile_top].substr(1,2);
	if(top_face == 2 || top_face ==3 || top_face == 4 || top_face ==5 || top_face == 6 || top_face == 7 top_face == 8 || top_face == 9)
	{
		return 1;
	}
	else if((discard_pile[pile_top].substr(0,1) == "S" || discard_pile[pile_top].substr(0,1) == "C") && discard_pile[pile_top].substr(1,2) == "A")
	{
		return 3;
	}
	else if((discard_pile[pile_top].substr(0,1) == "H" || discard_pile[pile_top].substr(0,1) == "D") && discard_pile[pile_top].substr(1,2) == "A")
	{
		return 5;
	}
	else return 2;
}


int main() {
	Player players[4];
	CardDeck deck;
	deck.shuffleDeck();
	bool winner = false;

	for(int i=0; i<4; ++i)
	{
		deck.dealCards(players[i],7);
	}

	while(winner == false)
	{
		int card_index;
		players[0].show_hand();
		cout<<"Which card would you like to pass? Enter the number:"<<endl;
		cin >>card_index;
		card_index--;

		players[0].passCard(players[1],card_index);
		players[1].auto_pass(players[2]);
		players[2].auto_pass(players[3]);
		players[3].auto_pass(players[0]);

		int discard_index;
		players[0].show_hand();

		for(int i=0; i<num_discard(deck.discardPile); ++i)
		{
			cout<<"Which card would you like to discard? Enter the number: "<<endl;
			cin >>discard_index;
			discard_index--;
			player[0].discard(discard_index, deck.discardPile);
		}

		for(int i=0; i<num_discard(deck.discardPile); ++i)
		{
			player[1].auto_discard(deck.discardPile);
		}

		for(int i=0; i<num_discard(deck.discardPile); ++i)
		{
			player[2].auto_discard(deck.discardPile);
		}

		for(int i=0; i<num_discard(deck.discardPile); ++i)
		{
			player[3].auto_discard(deck.discardPile);
		}
	}



}
