#include "HA.h"

using namespace std;


vector <int> codes;
map <char, vector <int> > table;

Node::Node(Node* Left, Node* Right)
{
	number = Left->number + Right->number;
	left = Left;
	right = Right;
}

bool compare::operator()(Node* l, Node* r) const
{
	{
		return(l->number < r->number);
	}
};

void AssgCodes(Node* root)
{
	if (root->left != nullptr)
	{
		//cout << root->left->number;
		codes.push_back(0);
		AssgCodes(root->left);
	}
	if (root->right != nullptr)
	{
		codes.push_back(1);
		AssgCodes(root->right);
	}
	if (root->left == nullptr || root->right == nullptr)
	{
		//cout << codes[0];
		//cout << codes[1];
		//cout << endl;
		table[root->symbol] = codes;		
	}
	if (codes.size() != 0)
		codes.pop_back();
};

void HA(string s, fstream &out)
{
	map <char, int> m;
	for (int i = 0; i < s.length(); i++)
	{
		char tech = s[i]; m[tech]++;
	}

	list <Node*> t;
	map <char, int>::iterator i;
	for (i = m.begin(); i != m.end(); i++)
	{
		Node* tech = new Node();
		tech->number = i->second;
		tech->symbol = i->first;
		t.push_back(tech);
	}

	while (t.size() != 1)
	{
		t.sort(compare());

		Node* LeftSon = t.front();
		t.pop_front();
		Node* RightSon = t.front();
		t.pop_front();

		Node* parent = new Node(LeftSon, RightSon);
		t.push_back(parent);
	}
	Node* root = t.front();

	//cout << root->left->left->number;

	AssgCodes(root);

	/*map <char, vector <int>>::iterator ii;	
	for (ii = table.begin(); ii != table.end(); ii++)
	{
		cout << ii->first << "---";
		out << ii->first << "---";
		int count = ii->second.size();
		for (int j = 0; j < count; j++)
		{
			cout << ii->second[j];
			out << ii->second[j];
		}
		cout << endl;
		out << endl;
	}*/
	
	for (int i = 0; i < s.length(); i++)
	{
		char tech = s[i];
		vector <int> x = table[tech];

		for (int j = 0; j < x.size(); j++)
		{
			out << x[j];
			cout << x[j];
		}
	}
	cout << endl << endl;
	out << endl << endl;
}