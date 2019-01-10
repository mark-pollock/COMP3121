//============================================================================
// Name        : weighPan.cpp
// Author      : mark pollock
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>

#include "weigh.h"
#include "find_solution.h"

using namespace std;


#define LIGHTER 1
#define HEAVIER 2







int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	// second integer is the coin number and the first integer says whether it is heavier (1) or lighter (2)
	for(int i = 1; i < 13; ++i){
		pair<int, int> p = make_pair<int, int>(LIGHTER, i);
		Weigh w(p);
		Find_solution sol = Find_solution(w);
		std::pair<int, int> s = sol.solve_problem();
	}
	for(int i = 1; i < 13; ++i){
		pair<int, int> p = make_pair<int, int>(HEAVIER, i);
		Weigh w(p);
		Find_solution sol = Find_solution(w);
		std::pair<int, int> s = sol.solve_problem();
	}

	return 0;
}





