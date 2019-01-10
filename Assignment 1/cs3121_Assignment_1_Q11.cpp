//============================================================================
// Name        : cs3121_Assignment_1_Q11.cpp
// Author      : mark pollock
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <array>
#include <cstdlib>
#include <algorithm>
#include <assert.h>

using namespace std;

int main() {
      const long size = 1000000;     
	array<int, size> A;


	srand(time(NULL));
	int dublicate = rand() % size;
	while(dublicate == 0)
		dublicate = rand() % size;



	A[0] = dublicate;
	for(int i = 1; i < size; ++i){
		A[i] = i;
	}
      
      random_shuffle(A.begin(), A.end());

      //for(int i = 0; i < size; ++i){
       //     cout << A[i] << "  ";
	//}

	bool B[size];
      

      for(int i = 0; i < size; ++i){
            B[i] = false;
      }

      for(int i = 0; i < size; ++i){
            if(B[A[i]]){
                  assert(A[i] == dublicate);
                  cout << "done" << endl;
                  return 0;
            }else
                  B[A[i]] = true;
            
      }
  
      
      cout << "failed" << endl;
	return 0;
}
