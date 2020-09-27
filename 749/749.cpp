#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};

class Tree {
public:
	vector<int> preorder;
	Node* root;

	void spanTree(Node* node, vector<int> inorder) {
		if (inorder.size() > 1) {//else will not have child nodes
			//cout << node->value << " ";//preorder traversal printing if put here

			for (auto itr = inorder.begin(); itr != inorder.end(); ++itr) {
				if (*itr == node->value) {//e.g. search 4 in inroder{4 7 2}
					if (itr != inorder.begin()) {//if this is not the leftmost node
						node->left = new Node(preorder[0]);
						preorder.erase(preorder.begin());
						spanTree(node->left, vector<int>(inorder.begin(), itr));
					}

					if (itr != inorder.end() - 1) {//if this is not the rightmost node
						node->right = new Node(preorder[0]);
						preorder.erase(preorder.begin());
						spanTree(node->right, vector<int>(itr + 1, inorder.end()));
					}

					break;
				}
			}
		}

		cout << node->value;//postorder traversal printing
		(node == root) ? cout << endl : cout << " ";//formatting
	}

	Tree(vector<int> preorder, vector<int> inorder) {
		this->preorder = preorder;//need to be kept as a track of record
		this->root = NULL;

		root = new Node(this->preorder[0]);
		this->preorder.erase(this->preorder.begin());
		spanTree(root, inorder);
	}
};

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

		Tree* tree = new Tree(preorder, inorder);

		preorder.clear();
		inorder.clear();
		delete tree;
	}

	return 0;
}