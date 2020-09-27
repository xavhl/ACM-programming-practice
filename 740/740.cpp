#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class List {
public:
    void traverse(int);
    void reset();
    void insert(int, int);
    void remove(int);
    void reverse(int, int);
    void query(int);
    List(){ head = NULL; ref = head;}
    
private:
    Node *head;
    Node *ref;
};

void List::traverse(int cnt) {
    for(int i=0; i<cnt-1; i++)
        ref = ref->next;
}

void List::reset() { ref=head; }

void List::insert(int ith, int data) {
    Node* n = new Node();
    n->data = data;
    
    if(ith == 0) {
        if(head==NULL)
            head = n;
        else
            ref->next = n;
        
        n->next = NULL;
        ref = n;
    }
    else {
        traverse(ith);
        n->next = ref->next;
        ref->next = n;
    }
}

void List::remove(int ith) {
    if(ith == 1)
        head = head->next;
    else {
        traverse(ith-1);
        ref->next = ref->next->next;
    }
}

void List::reverse(int ith, int jth) {
    Node *iprev, *i, *j, *jnext;// [... => i-1 => i => ... => j => jnext => ...]
	
	traverse(ith - 1);
	iprev = ref;

	if (ith == 1) {
		i = head;
		traverse((jth - ith) + 1);
	}
	else {
		i = iprev->next;
		traverse(1 + (jth - ith) + 1);//1: move ref from i-1 to i; (jth-ith)+1: move ref from ith to jth
	}
    
    j = ref;
    jnext = j->next;
    
    Node *pre, *cur, *nex;// [... =>  i  => i+1 => i+2 => ...]
    pre = i;              // [... => pre => cur => nex => ...]
    cur = pre->next;
    nex = cur->next;
    while(cur != jnext) { // [... => pre <= cur    nex => i+3 => ...]
        cur->next = pre;  // [... =>  i  <= i+1    i+2 => i+3 => ...]
        pre = cur;
        cur = nex;
		if(nex!=NULL)//eliminate last node(jth) case
			nex = nex->next;  // [... =>  i  <= pre    cur => nex => ...]
    }
    
	i->next = jnext;
	if (ith == 1)
		head = j;
	else	
		iprev->next = j;		 
}

void List::query(int ith) {
    traverse(ith);
    cout << ref->data << endl;
}

int main() {
    List list;
    int noOfEle, noOfOp;
    
    cin >> noOfEle;
    for(int i=0; i<noOfEle; i++) {
        int ele;
        cin >> ele;
        list.insert(0, ele);
    }
    list.reset();
    
    cin >> noOfOp;
    for(int i=0; i<noOfOp; i++) {
        int op, ith;
        cin >> op >> ith;
        
        if(op == 1) {
            int data;
            cin >> data;
            list.insert(ith, data);
        }
        else if(op == 2)
            list.remove(ith);
        else if(op == 3) {
            int jth;
            cin >> jth;
            list.reverse(ith, jth);
        }
        else if(op == 4)
            list.query(ith);
        else
            cout << "Invalid operation" << endl;
        
        list.reset();
    }
    
    return 0;
}
