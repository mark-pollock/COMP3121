#ifndef __FIND_SOLUTION_H__
#define __FIND_SOLUTION_H__

#include "weigh.h"

class Find_solution {

	public:
		//Find_solution() {};

		Find_solution(Weigh);


		std::pair<int, int> solve_problem();

	private:
		Weigh w;
};


#endif
