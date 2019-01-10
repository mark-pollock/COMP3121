#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <cstdio>


using namespace std;

void getLIS(vector<int>& weights, vector<int>& subset){
	vector<vector<int>> L(weights.size());
	L[0].push_back(weights[0]);

	for(int i = 1; i < weights.size(); ++i){
		for(int j = 0; j < i; ++j){
			if((weights[j] < weights[i]) && (L[i].size() < L[j].size() + 1)){
				L[i] = L[j];
			}
		}
		L[i].push_back(weights[i]);
	}
	int longestIndex = 0;
	for(int i = 0; i < L.size(); ++i){
		if(L[i].size() > L[longestIndex].size())
			longestIndex = i;
	}
	for(int i = 0; i < L[longestIndex].size(); ++i)
		subset.push_back(L[longestIndex][i]);
}


int main(int argc, char *argv[]){
	vector<int> weights;

	weights.push_back(6);
	weights.push_back(3);
	weights.push_back(1);
	weights.push_back(4);
	weights.push_back(5);
	weights.push_back(2);

	vector<int> subset;
	getLIS(weights, subset);

	for(int i = 0; i < subset.size(); ++i)
		cout << subset[i] << " ";

	cout << endl;

	return 0;
}
