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
	int weightedLength = 0;

	void inputTree(int);
	void constructTree();
	void cntWeightedLength(Node*, int);
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

void Tree::cntWeightedLength(Node* node, int lengthCnt) {
	if (node->freq == node->freqSum)
		weightedLength += node->freq * lengthCnt;
	else {
		cntWeightedLength(node->left, lengthCnt + 1);
		cntWeightedLength(node->right, lengthCnt + 1);
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
		tree->cntWeightedLength(tree->root, 0);
		cout << tree->weightedLength << endl;

		delete tree;
	}

	return 0;
}