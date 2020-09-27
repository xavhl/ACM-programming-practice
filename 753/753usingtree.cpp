#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	int weight;
	Node* parent;

	Node(Node* n) {
		parent = n;
		weight = 1;
	}
};

int xorWeight(string tree) {
	vector<int> w;
	Node* ptr = NULL;

	for (char c : tree) {
		if (c == '(') {//span a new child node
			Node* n = new Node(ptr);
			ptr = n;
		}
		else {//if(c == ')')
			if (ptr==NULL) {//case of first char == ')'
				cout << "invalid tree structure" << endl;
				break;
			}
			else {
				int temp = ptr->weight;//store child's weight
				w.push_back(temp);
				if (ptr->parent == NULL)//if this == root node
					break;
				else
					ptr = ptr->parent;//go up one level to be parent
					ptr->weight += temp;//update parent's weight
			}
		}
	}

	int xorSum = w[0];
	for (auto i = w.begin() + 1; i != w.end(); ++i)
		xorSum = xorSum ^ *i;

	return xorSum;
}

int main() {
	string tree;
	while (cin >> tree)
		cout << xorWeight(tree) << endl;

	return 0;
}