#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class Node {
public:
	int pixel, nodeColor, noOfNodes, size;
	Node* parent, * q1, * q2, * q3, * q4;

	Node(int, Node*, int);
	void flip();
	void update();
};

Node::Node(int pixel, Node* parent, int size/*, Node* q1, Node* q2, Node* q3, Node* q4*/) {
	this->pixel = pixel;//-1 mixed; 0 white; 1 black
	this->nodeColor = pixel;//-1 mixed; 0 white; 1 black
	this->noOfNodes = 0;
	this->size = size;
	this->parent = parent;
	this->q1 = this->q2 = this->q3 = this->q4 = NULL;
}

void Node::flip() {
	this->pixel = (pixel + 1) % 2;
	this->nodeColor = pixel;
}

void Node::update() {
	int noOfNodes;

	if (this->size == 2) {
		noOfNodes = (this->q1->pixel == this->q2->pixel &&
						this->q3->pixel == this->q4->pixel &&
						this->q1->pixel == this->q3->pixel) ? 1 : 5;
	}
	else {
		noOfNodes = ((this->q1->noOfNodes == 1 && this->q2->noOfNodes == 1 &&//check number of nodes
			this->q3->noOfNodes == 1 && this->q4->noOfNodes == 1) &&
			(this->q1->nodeColor == this->q2->nodeColor &&//check color of nodes
				this->q3->nodeColor == this->q4->nodeColor &&//even if same number of nodes (== 1)
				this->q1->nodeColor == this->q3->nodeColor)) ? 1
			: this->q1->noOfNodes + this->q2->noOfNodes +
			this->q3->noOfNodes + this->q4->noOfNodes + 1;
	}

	if (this->noOfNodes != noOfNodes) {
		this->noOfNodes = noOfNodes;
		//nodeColor

		if(this->parent!= NULL)
			this->parent->update();
	}
}

class Tree {
public:
	vector<vector<pair<int, Node*>>> image;
	Node* root;

	Tree(double);
	~Tree() { image.clear(); }
	void constructTree(Node*, int, int, int);
	//bool compareQuad(int, int, int);
	int countNodes(Node*);
	int getNodes() { return this->root->noOfNodes; }
	void flipNode(int, int);
};

Tree::Tree(double imageSize) {
	for (int j = 0; j < imageSize; ++j) {
		vector<pair<int, Node*>> row;

		string rowString;
		cin >> rowString;

		for (int k = 0; k < imageSize; ++k)
			row.push_back({ rowString[k] - 48, NULL });

		image.push_back(row);
	}

	root = new Node(-1, NULL, imageSize);
	constructTree(root, 0, 0, image.size());
	root->noOfNodes = countNodes(root);
}

void Tree::constructTree(Node* node, /*const vector<vector<pair<int, Node*>>>& image,*/ int x, int y, int size) {
	if (size == 2) {
		node->q1 = new Node(image[x][y].first, node, 1);
		image[x][y].second = node->q1;

		node->q2 = new Node(image[x + 1][y].first, node, 1);
		image[x + 1][y].second = node->q2;

		node->q3 = new Node(image[x][y + 1].first, node, 1);
		image[x][y + 1].second = node->q3;

		node->q4 = new Node(image[x + 1][y + 1].first, node, 1);
		image[x + 1][y + 1].second = node->q4;
	}
	else {
		int quadSize = size / 2;

		node->q1 = new Node(-1, node, quadSize);
		constructTree(node->q1, x, y, quadSize);

		node->q2 = new Node(-1, node, quadSize);
		constructTree(node->q2, x + quadSize, y, quadSize);

		node->q3 = new Node(-1, node, quadSize);
		constructTree(node->q3, x, y + quadSize, quadSize);

		node->q4 = new Node(-1, node, quadSize);
		constructTree(node->q4, x + quadSize, y + quadSize, quadSize);
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

int Tree::countNodes(Node* node) {
	if (node->size == 2) {
		/*int q1 = node->q1->noOfNodes;
		int q2 = node->q2->noOfNodes;
		int q3 = node->q3->noOfNodes;
		int q4 = node->q4->noOfNodes;
		|
		if (q1 == q2 && q3 == q4 && q1 == q3)*/
		if (node->q1->pixel == node->q2->pixel &&//check number of nodes
			node->q3->pixel == node->q4->pixel &&
			node->q1->pixel == node->q3->pixel) {
			node->nodeColor = node->q1->pixel;//record color of whole segments
			return 1;
		}
		else
			return 4 + 1;
	}
	else {
		//int quadSize = node->size / 2;

		node->q1->noOfNodes = countNodes(node->q1);
		node->q2->noOfNodes = countNodes(node->q2);
		node->q3->noOfNodes = countNodes(node->q3);
		node->q4->noOfNodes = countNodes(node->q4);

		/*int q1 = node->q1->noOfNodes;
		int q2 = node->q2->noOfNodes;
		int q3 = node->q3->noOfNodes;
		int q4 = node->q4->noOfNodes;*/

		if ((node->q1->noOfNodes == 1 && node->q2->noOfNodes == 1 &&//check number of nodes
			node->q3->noOfNodes == 1 && node->q4->noOfNodes == 1) &&
			(node->q1->nodeColor == node->q2->nodeColor &&//check color of nodes
				node->q3->nodeColor == node->q4->nodeColor &&//even if same number of nodes (== 1)
				node->q1->nodeColor == node->q3->nodeColor)) {//sub squares may have different colors
			node->nodeColor = node->q1->pixel;
			return 1;
		}
		else
			return node->q1->noOfNodes + node->q2->noOfNodes + 
			node->q3->noOfNodes + node->q4->noOfNodes + 1;
	}
}

void Tree::flipNode(int row, int col) {
	this->image[row][col].second->flip();
	
}

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		int sizeExponent;
		cin >> sizeExponent;

		double imageSize = pow(2, sizeExponent);
		Tree* tree = new Tree(imageSize);
		cout << tree->getNodes() << endl;

		int noOfOperations;
		cin >> noOfOperations;
		for (int j = 0; j < noOfOperations; ++j) {
			int row, col;
			cin >> row >> col;

			tree->flipNode(row, col);
			//tree->image[row][col].second->flip();
			cout << tree->getNodes() << endl;
		}

		delete tree;
	}

	return 0;
}