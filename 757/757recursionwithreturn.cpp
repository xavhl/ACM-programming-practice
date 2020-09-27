#include <iostream>
#include <queue>
using namespace std;

class Node {
public://need check
	int freq, freqSum;
	Node* left, * right;

	Node(int freq) {
		this->freq = this->freqSum = freq;
		this->left = this->right = NULL;
	}

	Node(int freqSum, Node* left, Node* right) {
		this->freq = 0;
		this->freqSum = freqSum;
		this->left = left;
		this->right = right;
	}
};

class comparator {
public:
	bool operator()(Node* a, Node* b) { return a->freqSum > b->freqSum; }
};

class Tree {
public://need check
	Node* root = NULL;
	priority_queue<Node*, vector<Node*>, comparator> minHeap;

	void inputTree(int);
	void constructTree();
	int getWeightedLength(Node*, int);
};

void Tree::inputTree(int noOfSymbols) {
	for (int i = 0; i < noOfSymbols; ++i) {
		int freq;
		cin >> freq;
		minHeap.push(new Node(freq));
	}
	constructTree();
}

void Tree::constructTree() {
	while (minHeap.size() > 1) {
		Node* a = minHeap.top(); minHeap.pop();
		Node* b = minHeap.top(); minHeap.pop();

		minHeap.push(new Node(a->freqSum + b->freqSum, a, b));
	}

	this->root = minHeap.top();
	minHeap.pop();
}

int Tree::getWeightedLength(Node* node, int lengthCnt) {
	if (node->freq == node->freqSum)
		return node->freq * lengthCnt;
	else {
		int left = getWeightedLength(node->left, lengthCnt + 1);
		int right = getWeightedLength(node->right, lengthCnt + 1);
		return left + right;
	}
}

int main() {
	int noOfSymbols;
	while (cin>>noOfSymbols) {
		if (noOfSymbols == 0) {
			cout << 0 << endl;
			continue;
		}

		Tree* tree = new Tree();
		
		tree->inputTree(noOfSymbols);
		cout << tree->getWeightedLength(tree->root, 0) << endl;

		delete tree;
	}

	return 0;
}