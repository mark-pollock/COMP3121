#include <iostream>
#include <vector>
#include <algorithm>

#include "weigh.h"


using namespace std;

#define LEFT 1
#define RIGHT 2
#define SAME 3
#define LIGHTER 1
#define HEAVIER 2



Weigh::Weigh(std::pair<int, int> p2){
	p = p2;
}


// returns which is heavier
int Weigh::weigh_action(vector<int> l, vector<int> r){
	int coin = p.second;

	if (find(l.begin(), l.end(), coin) != l.end()){
		// coin is in left
		if(p.first == LIGHTER)
			return RIGHT;
		else
			return LEFT;
	}
	else if(find(r.begin(), r.end(), coin) != r.end()){
		//coin is in right
		if(p.first == LIGHTER)
			return LEFT;
		else
			return RIGHT;
	}else
		return SAME;
}


