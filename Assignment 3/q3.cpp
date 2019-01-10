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



typedef struct node{
	int funRating;
	node *parent;
	vector<node*> children;
	string name;
	vector<string> listUsingNode;
	vector<string> listWithoutUsingNode;
} node;

typedef struct tree{
	node *root;
} tree;

void createNode(node *n, int fR, node *p, const string &name){
	n->funRating = fR;
	n->parent = p;
	n->name = name;
	return;
}


int main(int argc, char *argv[]){

	tree *t = (tree*)malloc(sizeof(tree));
	t->root = (node*)malloc(sizeof(node));
	const string s[21] = {"president", "fred", "alfred", "nick", "jasmine", "kate", "bob", "freya", "ellen", "meg", "dom", "tammy", "mark", "megan", "claire", "brenda", "greig", "terry", "tom", "dan", "cassie"};
	//s[0] = "president";
	createNode(t->root, 11, NULL, s[0]);
	node* n[10];
	for(int i = 0; i < 3; ++i){
		n[i] = (node*)malloc(sizeof(node));
	}
	//s[1] = "fred";
	//s[2] = "alfred";
	//s[3] = "nick";
	createNode(n[0], 22, t->root, s[1]);
	createNode(n[1], 16, t->root, s[2]);
	createNode(n[2], 7, t->root, s[3]);

	for(int i = 0; i < 3; ++i){
		t->root->children.push_back(n[i]);
	}


	for(int i = 0; i < 8; ++i){
		n[i] = (node*)malloc(sizeof(node));
	}

	//s[4] = "jasmine";
	//s[5] = "kate";
	//s[6] = "bob";
	createNode(n[0], 8, t->root->children[0], s[4]);
	createNode(n[1], 10, t->root->children[0], s[5]);
	createNode(n[2], 17, t->root->children[0], s[6]);
	for(int i = 0; i < 3; ++i){
		t->root->children[0]->children.push_back(n[i]);
	}

	//s[7] = "freya";
	//s[8] = "ellen";
	createNode(n[3], 10, t->root->children[1], s[7]);
	createNode(n[4], 21, t->root->children[1], s[8]);
	for(int i = 3; i < 5; ++i){
			t->root->children[1]->children.push_back(n[i]);
	}

	//s[9] = "meg";
	//s[10] = "dom";
	//s[11] = "tammy";

	createNode(n[5], 22, t->root->children[2], s[9]);
	createNode(n[6], 2, t->root->children[2], s[10]);
	createNode(n[7], 19, t->root->children[2], s[11]);
	for(int i = 5; i < 8; ++i){
		t->root->children[2]->children.push_back(n[i]);
	}

	for(int i = 0; i < 5; ++i){
		n[i] = (node*)malloc(sizeof(node));
	}

	/*
	s[12] = "mark";
	s[13] = "megan";
	s[14] = "claire";
	s[15] = "brenda";
	s[16] = "greig";*/
	createNode(n[0], 6, t->root->children[0]->children[0], s[12]);
	t->root->children[0]->children[0]->children.push_back(n[0]);
	createNode(n[1], 27, t->root->children[0]->children[2], s[13]);
	t->root->children[0]->children[2]->children.push_back(n[1]);
	createNode(n[2], 23, t->root->children[0]->children[2], s[14]);
	t->root->children[0]->children[2]->children.push_back(n[2]);

	createNode(n[3], 22, t->root->children[2]->children[2], s[15]);
	t->root->children[2]->children[2]->children.push_back(n[3]);
	createNode(n[4], 16, t->root->children[2]->children[2], s[16]);
	t->root->children[2]->children[2]->children.push_back(n[4]);

	for(int i = 0; i < 4; ++i){
		n[i] = (node*)malloc(sizeof(node));
	}

	/*s[17] = "terry";
	s[18] = "tom";
	s[19] = "dan";
	s[20] = "cassie";*/
	createNode(n[0], 21, t->root->children[0]->children[2]->children[0], s[17]);
	createNode(n[1], 22, t->root->children[0]->children[2]->children[0], s[18]);
	createNode(n[2], 28, t->root->children[0]->children[2]->children[0], s[19]);
	createNode(n[3], 22, t->root->children[0]->children[2]->children[0], s[20]);

	for(int i = 0; i < 4; ++i){
		t->root->children[0]->children[2]->children[0]->children.push_back(n[i]);
	}



	return 0;
}
