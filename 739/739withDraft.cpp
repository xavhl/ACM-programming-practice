#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class List {
public:
	void traverse(int);
    void insert(int, int);
	void remove(int);
	void print(int);
    void resetRef();
    List() {head = NULL; ref = head;}
    void printAll();
private:
	Node* head;
    Node* ref;
};

void List::traverse(int cnt) {
    for(int i=1; i<cnt; i++)
        ref = ref->next;
}

void List::insert(int i, int data) {
    Node* n = new Node();
    n->data = data;
    
    if(i==0) {
        if(head==NULL)
            head = n;
        else
            ref->next = n;
        
        n->next = NULL;
        ref = n;
    }
    else {
        traverse(i);
        
        n->next = ref->next;
        ref->next = n;
        ref = n;
    }
}

void List::remove(int i) {
    traverse(i-1);
    ref->next = ref->next->next;
    ref = ref->next;
}

void List::print(int i) {
    traverse(i);
    cout << ref->data << endl;
}

void List::resetRef() {
    ref->next = head;
    ref = head;
}

void List::printAll() {
    Node* n = head;
    
    do {
        cout<<n->data<<" ";
        n = n->next;
    } while(n!=head);
}

int main()
{
    List Circle;
    
	int noOfStu;
	cin >> noOfStu;
    //set up circle
	for (int i = 0; i < noOfStu; i++) {
		int tag;
		cin >> tag;
        
        Circle.insert(0, tag);
	}
    Circle.resetRef();//point reference to first student

    //Circle.printAll();//testing
    cout<<endl;
    
    int noOfOp;
    cin >> noOfOp;
    for(int i=0; i<noOfOp; i++) {
        int op, ith;
        cin >> op >> ith;
        
        if(op==1) {
            int tag;
            cin >> tag;
            Circle.insert(ith, tag);
        }
        else if(op==2) {
            Circle.remove(ith);
        }
        else if(op==3){
            Circle.print(ith);
        }
        else {
            cout << "Invalid operation" << endl;
            break;
        }
    }
    /* testing
    Circle.insert(3, 5);
    Circle.printAll();
    cout<<endl;
    
    Circle.remove(2);
    Circle.printAll();
    cout<<endl;
    
    Circle.print(1);
    cout<<endl;
    Circle.print(2);
    */
	return 0;
}
