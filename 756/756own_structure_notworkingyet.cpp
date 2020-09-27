#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	vector<int> maxHeap;
	int sum;

	int parent(int i) { return (i - 1) / 2; }
	int lchild(int i) { return (2 * i + 1); }
	int rchild(int i) { return (2 * i + 2); }

public:
	void insert(int);
	int deleteMax();
	void print() { cout << sum << endl; };

	Heap() : maxHeap() {
		sum = 0;
	}

	~Heap() {
		maxHeap.clear();
	}
};

void Heap::insert(int value) {
	maxHeap.push_back(value);
	sum += value;
	
	int child = maxHeap.size() - 1;
	while (child > 0 && maxHeap[parent(child)] < maxHeap[child]) {
		swap(maxHeap[parent(child)], maxHeap[child]);
		child = parent(child);
	}

	//testing
	//print();
}

int Heap::deleteMax() {
	int parent = 0;
	int max = maxHeap[parent], lastChild = maxHeap.size() - 1;
	sum -= max;

	maxHeap[parent] = maxHeap[lastChild];
	maxHeap.erase(maxHeap.begin() + lastChild);
	
	int child = lchild(parent);//if node does not have right child
	if (rchild(parent) < lastChild)//if node does have right child/ both children
		child = (maxHeap[lchild(parent)] < maxHeap[rchild(parent)]) ? rchild(parent) : lchild(parent);//compare and choose one with larger value

	while (child < lastChild && maxHeap[parent] < maxHeap[child]) {
		child = (maxHeap[lchild(parent)] < maxHeap[rchild(parent)]) ? rchild(parent) : lchild(parent);//choose child with larger value to swap

		swap(maxHeap[parent], maxHeap[child]);
		parent = child;
	}

	//testing
	//print();

	return max;
}

int main() {
	int noOfOperations;
	while (cin >> noOfOperations) {
		Heap* heap = new Heap();

		for (int i = 0; i < noOfOperations; ++i) {
			char operation;
			cin >> operation;

			if (operation == 'a') {
				int value;
				cin >> value;
				heap->insert(value);
			}
			else if (operation == 'p')
				heap->deleteMax();
			else//operation == 'r'
				heap->print();
		}

		delete heap;
	}
	/*
	Heap* heap = new Heap();
	heap->insert(1);
	heap->insert(2);
	heap->insert(3);
	heap->insert(5);
	heap->print();
	heap->deleteMax();
	heap->print();*/

	return 0;
}