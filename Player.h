/*
 * Player.h
 *
 *  Created on: Jul 23, 2018
 *      Author: Haojin Li
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "Deck.h"

class Player
{
public:
	std::vector<std::string> hand;

	std::string get_maxsuit()
	{
		int H = 0, D = 0, C = 0, S = 0;
		for(int i=0; i<hand.size(); ++i)
		{
			if(hand[i].substr(0,1) == "H") H++;
			else if(hand[i].substr(0,1) == "D") D++;
			else if(hand[i].substr(0,1) == "C") C++;
			else if(hand[i].substr(0,1) == "S") S++;
		}

		std::string max_suit;
		if(std::max(std::max(H,D), std::max(C,S)) == H) max_suit  = "H";
		else if(std::max(std::max(H,D), std::max(C,S)) == D) max_suit  = "D";
		else if(std::max(std::max(H,D), std::max(C,S)) == C) max_suit  = "C";
		else if(std::max(std::max(H,D), std::max(C,S)) == S) max_suit  = "S";

		return max_suit;
	}

	std::string get_minsuit()
	{
		int H = 0, D = 0, C = 0, S = 0;
		for(int i=0; i<hand.size(); ++i)
		{
			if(hand[i].substr(0,1) == "H") H++;
			else if(hand[i].substr(0,1) == "D") D++;
			else if(hand[i].substr(0,1) == "C") C++;
			else if(hand[i].substr(0,1) == "S") S++;
		}

		std::string min_suit;
		if(std::max(std::min(H,D), std::min(C,S)) == H) min_suit  = "H";
		else if(std::min(std::min(H,D), std::min(C,S)) == D) min_suit  = "D";
		else if(std::min(std::min(H,D), std::min(C,S)) == C) min_suit  = "C";
		else if(std::min(std::min(H,D), std::min(C,S)) == S) min_suit  = "S";

		return min_suit;
	}

	void passCard(Player &p,int index)
	{
		std::string temp = hand[index];
		hand.erase(hand.begin() + index);
		p.hand.push_back(temp);
	}

	void discard(int index, std::vector<std::string> discardpile)
	{
		std::string temp = hand[index];
		hand.erase(hand.begin() + index);
		discardpile.push_back(temp);
	}

	void auto_pass(Player &p)
	{
		std::string my_max = get_maxsuit();
		std::string my_min = get_minsuit();
		for(int i=0; i<hand.size(); ++i)
		{
			if(hand[i].substr(0,1) == my_min && hand[i].substr(0,1) == p.get_minsuit()) passCard(p,i);
			else if(hand[i].substr(0,1) == my_min && hand[i].substr(0,1) != p.get_maxsuit()) passCard(p,i);
			else if(hand[i].substr(0,1) == my_min) passCard(p,i);
		}
	}

	void auto_discard(std::vector<std::string> discardpile)
	{
		std::string my_min = get_minsuit();
		for(int i=0; i<hand.size(); ++i)
		{
			if(hand[i].substr(0,1) == my_min)
			{
				discardpile.push_back(hand[i]);
				hand.erase(hand.begin() + i);
			}
		}
	}

	void show_hand()
	{
		for(int i=0; i<hand.size(); ++i)
		{
			std::cout<< hand[i]<<" ";
		}
		std::cout<<"\n";
	}
};

#endif /* PLAYER_H_ */
