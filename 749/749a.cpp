#include <iostream>
#include <vector>
using namespace std;

class Node {
private:	
	//vector<int> preorder, inorder;

public:
	int value;
	Node* left;
	Node* right;

	Node(int value/*, vector<int> preorder, vector<int> inorder*/) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
		//this->preorder = preorder;
		//this->inorder = inorder;
	}
};

class Tree {
public:
	int noOfNodes;
	vector<int> preorder, inorder;
	Node* root;

	Tree(int noOfNodes, vector<int> preorder, vector<int> inorder) {
		this->noOfNodes = noOfNodes;
		this->preorder = preorder;
		this->inorder = inorder;
		this->root = NULL;
		construct();
	}

	void construct();
	void postorderTraversal();
};

void Tree::construct() {
	root = new Node(inorder[0]);
	inorder.erase(inorder.begin());
}

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		vector<int> preorder, inorder;
		int noOfNodes;
		cin >> noOfNodes;

		for (int j = 0; j < noOfNodes; ++j) {
			int value;
			cin >> value;
			preorder.push_back(value);
		}
		for (int j = 0; j < noOfNodes; ++j) {
			int value;
			cin >> value;
			inorder.push_back(value);
		}

		Tree* tree = new Tree(noOfNodes, preorder, inorder);
		tree->postorderTraversal();

		preorder.clear();
	}

	return 0;
}