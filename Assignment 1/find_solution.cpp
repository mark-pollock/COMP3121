#include <iostream>
#include <vector>
#include <algorithm>
#include "find_solution.h"
#include "weigh.h"

#define LEFT 1
#define RIGHT 2
#define SAME 3
#define LIGHTER 1
#define HEAVIER 2


	Find_solution::Find_solution(Weigh w){
		this->w = w;
	}

	std::pair<int, int> Find_solution::solve_problem(){
		int coin;
		int diff;

		std::vector<int> l;
		std::vector<int> r;

		for(int i = 0; i < 5; ++i)
			l.push_back(i);
		for(int i = 5; i < 9; ++i)
			r.push_back(i);

		//outcome 1 - P1 matches P2
		int result0 = w.weigh_action(l, r);

		if(result0 == SAME){
			l.clear();
			r.clear();
			l.push_back(9);
			l.push_back(10);
			l.push_back(11);
			r.push_back(1);
			r.push_back(2);
			r.push_back(3);

			int result = w.weigh_action(l, r);
			if(result == SAME){
				//counterfeit is coin 12
				coin = 12;
				l.clear();
				r.clear();
				l.push_back(1);
				r.push_back(12);
				if(w.weigh_action(l, r) == LEFT){
					std::cout << "coin 12 is lighter" << std::endl;
					diff = LIGHTER;
				}else{
					std::cout << "coin 12 is heavier" << std::endl;
					diff = HEAVIER;
				}
			}else{
				l.clear();
				r.clear();
				l.push_back(9);
				r.push_back(10);
				int result2 = w.weigh_action(l, r);
				if(result == LEFT && result2 == LEFT){
					std::cout << "coin 9 is heavier" << std::endl;
					coin = 9;
					diff = HEAVIER;
				}else if(result == LEFT && result2 == RIGHT){
					std::cout << "coin 10 is heavier" << std::endl;
					coin = 10;
					diff = HEAVIER;
				}else if(result == RIGHT && result2 == LEFT){
					std::cout << "coin 10 is lighter" << std::endl;
					coin = 10;
					diff = LIGHTER;
				}else if(result == RIGHT && result2 == RIGHT){
					std::cout << "coin 9 is lighter" << std::endl;
					coin = 9;
					diff = LIGHTER;
				}else if(result == LEFT && result2 == SAME){
					std::cout << "coin 11 is heavier" << std::endl;
					coin = 11;
					diff = HEAVIER;
				}else if(result == RIGHT && result2 == SAME){
					std::cout << "coin 11 is lighter" << std::endl;
					coin = 11;
					diff = LIGHTER;
				}
			}


		}else{
			l.clear();
			r.clear();
			l.push_back(1);
			l.push_back(2);
			l.push_back(5);
			l.push_back(6);

			r.push_back(7);
			r.push_back(9);
			r.push_back(10);
			r.push_back(11);

			int result2 = w.weigh_action(l, r);

			if(result2 == SAME){
				// counterfeit coin is either 1c, 1d or 2d ie 3, 4, 8
				l.clear();
				r.clear();
				l.push_back(3);
				l.push_back(8);
				r.push_back(9);
				r.push_back(10);
				int result3 = w.weigh_action(l, r);
				if(result3 == SAME){
					// coin 4 is counterfeit
					if(result0 == LEFT){
						std::cout << "coin 4 is heavier" << std::endl;
						coin = 4;
						diff = HEAVIER;
					}else if(result0 == RIGHT){
						std::cout << "coin 4 is lighter" << std::endl;
						coin = 4;
						diff = LIGHTER;
					}
				}else if(result3 == LEFT){
					if(result0 == LEFT){
						std::cout << "coin 3 is heavier" << std::endl;
						coin = 3;
						diff = HEAVIER;
					}else if(result0 == RIGHT){
						std::cout << "coin 8 is heavier" << std::endl;
						coin = 8;
						diff = HEAVIER;
					}
				}else if(result3 == RIGHT){
					if(result0 == LEFT){
						std::cout << "coin 8 is lighter" << std::endl;
						coin = 8;
						diff = LIGHTER;
					}
					else if(result0 == RIGHT){
						std::cout << "coin 3 is lighter" << std::endl;
						coin = 3;
						diff = LIGHTER;
					}

				}
			}else if(result2 == LEFT){
				// 1a + 1b + 2a + 2b is heavier than 2c + 3 genuine.
				if(result0 == LEFT){
					l.clear();
					r.clear();
					l.push_back(1);
					l.push_back(7);
					r.push_back(9);
					r.push_back(10);
					int result7 = w.weigh_action(l, r);
					if(result7 == SAME){
						std::cout << "coin 2 is heavier" << std::endl;
						coin = 2;
						diff = HEAVIER;
					}else if(result7 == LEFT){
						std::cout << "coin 1 is heavier" << std::endl;
						coin = 1;
						diff = HEAVIER;
					}else if(result7 == RIGHT){
						std::cout << "coin 7 is lighter" << std::endl;
						coin = 7;
						diff = LIGHTER;
					}
				}else if(result0 == RIGHT){
					l.clear();
					r.clear();
					l.push_back(5);
					r.push_back(9);
					int result8 = w.weigh_action(l, r);
					if(result8 == LEFT){
						std::cout << "coin 5 is heavier" << std::endl;
						coin = 5;
						diff = HEAVIER;
					}else{
						std::cout << "coin 6 is heavier" << std::endl;
						coin = 6;
						diff = HEAVIER;
					}
				}

			}else if(result2 == RIGHT){
				// 1a + 1b + 2a + 2b is lighter than 2c + 3 genuine
				// therefore 1a, 1b is lighter or 2c is heavier or 2a, 2b is lighter.
				if(result0 == LEFT){
					// counterfeit coin is 2a, 2b
					l.clear();
					r.clear();
					l.push_back(5);
					r.push_back(6);
					int result5 = w.weigh_action(l, r);
					if(result5 == LEFT){
						std::cout << "coin 6 is lighter" << std::endl;
						coin = 6;
						diff = LIGHTER;
					}else if(result5 == RIGHT){
						std::cout << "coin 5 is lighter" << std::endl;
						coin = 5;
						diff = LIGHTER;
					}
				}else if(result0 == RIGHT){
					// 1a, 1b are lighter or 2c is heavier.
					l.clear();
					r.clear();
					l.push_back(1);
					l.push_back(7);
					r.push_back(9);
					r.push_back(10);
					int result6 = w.weigh_action(l, r);
					if(result6 == SAME){
						std::cout << "coin 2 is lighter" << std::endl;
						coin = 2;
						diff = LIGHTER;
					}else if(result6 == LEFT){
						std::cout << "coin 7 is heavier" << std::endl;
						coin = 7;
						diff = HEAVIER;

					}else if(result6 == RIGHT){
						std::cout << "coin 1 is lighter" << std::endl;
						coin = 1;
						diff = LIGHTER;
					}
				}
			}


		}


		return std::make_pair<int, int>(coin, diff);
	}
