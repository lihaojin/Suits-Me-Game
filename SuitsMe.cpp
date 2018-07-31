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

	for(int i=0; i<4; ++i)
	{
		deck.dealCards(players[i],7);
		//players[i].show_hand();
	}



}
