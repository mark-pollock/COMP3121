#ifndef __WEIGH_H__
#define __WEIGH_H__
#include <vector>

class Weigh {

	public:
		Weigh() {};
		Weigh(std::pair<int, int>);
		int weigh_action(std::vector<int> l, std::vector<int> r);


	private:
		std::pair<int, int> p;


};


#endif
