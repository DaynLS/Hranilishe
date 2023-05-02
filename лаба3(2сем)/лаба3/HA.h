#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>

using namespace std;


struct Node
{
public:
	int number;
	char symbol;
	Node* left = nullptr, * right = nullptr;
	Node() {};
	~Node() {};
	Node(Node* Left, Node* Right);
};

struct compare
{
	bool operator()(Node* l, Node* r) const;	
};

void AssgCodes(Node* root);
void HA(string s, fstream &out );