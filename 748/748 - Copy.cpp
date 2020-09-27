#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class Node {
public:
	int pixel, noOfNodes;
	Node* parent, * q1, * q2, * q3, * q4;

	Node(int, Node*);
	void flip();
	void updateParent();
};

Node::Node(int pixel, Node* parent/*, Node* q1, Node* q2, Node* q3, Node* q4*/) {
	this->pixel = pixel;
	this->noOfNodes = 1;
	this->parent = parent;
	this->q1 = this->q2 = this->q3 = this->q4 = NULL;
}

void Node::flip() {
	pixel = (pixel + 1) % 2;
	updateParent();
}

class Tree {
public:
	vector<vector<pair<int, Node*>>> image;
	Node* root;
	int noOfNodes;

	Tree(int);
	~Tree() { image.clear(); }
	void constructTree(Node*, int, int, int);
	bool compareQuad(int, int, int);
	int countNodes(Node*, int, int, int);
};

Tree::Tree(int sizeExponent) {
	int imageSize = pow(2, sizeExponent);

	for (int j = 0; j < imageSize; ++j) {
		vector<pair<int, Node*>> row;

		string rowString;
		cin >> rowString;

		for (int k = 0; k < imageSize; ++k)
			row.push_back({ rowString[k] - 48, NULL });

		image.push_back(row);
	}

	root = new Node(-1, NULL);
	constructTree(root, 0, 0, image.size());
}

void Tree::constructTree(Node* node, /*const vector<vector<pair<int, Node*>>>& image,*/ int x, int y, int size) {
	if (size == 2) {
		node->q1 = new Node(image[x][y].first, node);
		image[x][y].second = node->q1;

		node->q2 = new Node(image[x + 1][y].first, node);
		image[x + 1][y].second = node->q2;

		node->q3 = new Node(image[x][y + 1].first, node);
		image[x][y + 1].second = node->q3;

		node->q4 = new Node(image[x + 1][y + 1].first, node);
		image[x + 1][y + 1].second = node->q4;
	}
	else {
		int quadSize = size / 2;

		node->q1 = new Node(-1, node);
		constructTree(node->q1, 0, 0, quadSize);

		node->q2 = new Node(-1, node);
		constructTree(node->q2, 0 + quadSize, 0, quadSize);

		node->q3 = new Node(-1, node);
		constructTree(node->q3, 0, 0 + quadSize, quadSize);

		node->q4 = new Node(-1, node);
		constructTree(node->q4, 0 + quadSize, 0 + quadSize, quadSize);
	}
}
/*
bool Tree::compareQuad(int x, int y, int quadSize) {
	bool isIdentical = false;

	int q1 = image[x][y].first;
	int q2 = image[x + quadSize][y].first;
	int q3 = image[x][y + quadSize].first;
	int q4 = image[x + quadSize][y + quadSize].first;

	if (q1 == q2 && q3 == q4 && q1 == q3)
		isIdentical = true;

	return isIdentical;
}*/

int Tree::countNodes(Node* node, int x, int y, int size) {
	if (size == 2) {
		int q1 = node->q1->noOfNodes;
		int q2 = node->q2->noOfNodes;
		int q3 = node->q3->noOfNodes;
		int q4 = node->q4->noOfNodes;

		if (q1 == q2 && q3 == q4 && q1 == q3)
			return 1;
		else
			return 4 + 1;
	}
	else {
		int quadSize = size / 2;

		int q1 = countNodes(node->q1, x, y, quadSize);
		int q2 = countNodes(node->q2, x + quadSize, y, quadSize);
		int q3 = countNodes(node->q3, x, y + quadSize, quadSize);
		int q4 = countNodes(node->q4, x + quadSize, y + quadSize, quadSize);

		if(compare)
	}
}

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		int sizeExponent;
		cin >> sizeExponent;

		Tree* tree = new Tree(sizeExponent);


		delete tree;
	}

	return 0;
}