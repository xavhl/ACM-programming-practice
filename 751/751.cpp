#include <iostream>
#include <stack>
#include <string>
using namespace std;

//class Node {
//public:
//    int data;
//    Node* next;
//};
//
//class MyStack {
//public:
//    MyStack() { topNode = NULL; }
//    void pop();
//    void push(int);
//    int top();
//
//private:
//    Node *topNode;
//};
//
//void MyStack::push(int num) {
//    Node* n = new Node();
//    n->data = num;
//
//    if(topNode == NULL)
//        n->next = NULL;
//    else
//        n->next = topNode;
//
//    topNode = n;
//}
//
//void MyStack::pop() {
//    if(topNode->next != NULL)
//        topNode = topNode->next;
//}
//
//int MyStack::top() {
//    if(topNode == NULL)
//        return 0;
//    else
//        return topNode->data;
//}

int main() {
    //MyStack rpn;
    stack <int> rpn;
    
    string input;
    while(getline(cin, input)) {
        for(char&c : input) {
            if('0' <= c && c <= '9') {
                int num = c - '0';
                rpn.push(num);
            }
            else if(c == ' ')
                ;
            else {
                int op1, op2, result = 0;
                
                op2 = rpn.top();
                rpn.pop();
                op1 = rpn.top();
                rpn.pop();
                
                if(c == '+')
                    result = op1 + op2;
                else if(c == '-')
                    result = op1 - op2;
                else if(c == '*')
                    result = op1 * op2;
                else if(c == '/')
                    result = op1 / op2;
                
                rpn.push(result);
            }
        }
        
        cout << rpn.top() << endl;
        rpn.pop();
    }
    
    return 0;
}
