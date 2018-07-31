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
		players[1].show_hand();
		players[2].show_hand();
		cout<<"Which card would you like to pass? Enter the number."<<endl;
		cin >>card_index;
		card_index--;
		players[0].passCard(players[1],card_index);
		players[1].auto_pass(players[2]);
		players[0].show_hand();
		players[1].show_hand();
		players[2].show_hand();
		cout<<"\n";
	}



}
