#include <iostream>
using namespace std;

class Node {
public:
	//Node(Node* n, int d);
	Node* getNext();
	void setNext(Node* setter);
	int getData();
	void setData(int data);
	
private:
	Node* next;
	int data;
};

//header
//Node::Node(Node* n, int d) { next = n; data = d; }
Node* Node::getNext() {	return next; }
void Node::setNext(Node* setter) { next = setter; }
int Node::getData() { return data; }
void Node::setData(int data) { this->data = data; }

void insert(Node** pre, Node** ref, int data) {
	//Node* n = new Node((*pre)->getNext(), data);
	Node* n = new Node();
	n->setData(data);
	n->setNext((*pre)->getNext());
	(*pre)->setNext(n);

	(*ref)->setNext(n);
}

Node* traverse(Node** head, int cnt) {
	for (int i = 0; i < cnt; i++) {
		;
	}
	return NULL;
}

void remove(Node** pre, Node** ref) {
	(*pre)->setNext((*pre)->getNext());

	(*ref)->setNext((*pre)->getNext());
}
void print();

int main()
{
	Node* head = NULL;
	Node* ref = head;

	Node** headptr = &head;
	Node** refptr = &ref;

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		Node* n = new Node();
		int tag;

		cin >> tag;				
		n->setData(tag);
		n->setNext(NULL);

		if (head == NULL)			
			head = n;
		else
			ref->setNext(n);

		ref = n;
	}
	ref = head;
	//after initialisation
	//point ref to first 
	//point last to first


	//cout testing
	for (int i = 0; i < num; i++) {
		cout << ref->getData() << endl;
		ref = ref->getNext();
	}

	return 0;
}