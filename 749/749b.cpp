#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node(int, vector<int>);
};

class Tree {
public:
	int noOfNodes;
	static vector<int> preorder;
	Node* root;

	Tree(int noOfNodes, vector<int> preorder, vector<int> inorder);

	//void postorderTraversal();
};

Node::Node(int value, vector<int> inorder) {
	this->value = value;
	this->left = NULL;
	this->right = NULL;

	if (inorder.size() > 1) {
		for (auto itr = inorder.begin(); itr != inorder.end(); ++itr) {
			if (*itr == value) {
				left = new Node(Tree::preorder[0], vector<int>(inorder.begin(), itr));
				Tree::preorder.erase(Tree::preorder.begin());

				right = new Node(Tree::preorder[0], vector<int>(itr, inorder.end()));
				Tree::preorder.erase(Tree::preorder.begin());

				break;
			}
		}
	}

	cout << value << " ";
}

Tree::Tree(int noOfNodes, vector<int> preorder, vector<int> inorder) {
	this->noOfNodes = noOfNodes;
	this->preorder = preorder;
	this->root = NULL;

	root = new Node(preorder[0], inorder);
	preorder.erase(preorder.begin());
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
		//tree->postorderTraversal();

		preorder.clear();
		inorder.clear();
	}

	return 0;
}