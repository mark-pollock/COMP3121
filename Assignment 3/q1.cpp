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

int getOccurenceCount(string a, string b){
	char a0 = a[0];
	char bchar = b[0];
	int occurence = 0;
	for(int i = 0; i < b.size(); ++i){
		if(a0 == b[i]){
			if(a.size() == 1)
				occurence++;
			else
				occurence += getOccurenceCount(a.substr(1, a.size() - 1), b.substr(i + 1, b.size() - 1));
		}
	}
	return occurence;
	return 0;
}


int main(int argc, char *argv[]){
	string a;
	string b;
	a = argv[1];
	b = argv[2];

	cout << getOccurenceCount(a, b) << endl;

	return 0;
}
