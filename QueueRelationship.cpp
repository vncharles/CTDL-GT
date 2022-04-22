#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *link;
};

struct List {
	Node* first;
	Node* last;
};

void initList(List &l){
	l.first = l.last = NULL;
}

// tao 1 node
Node* getNode(int x){
	Node *p = new Node;
	if(p == NULL) {
		cout << "Khong du bo nho";
		exit(1);
	}
	p->data = x;
	p->link = NULL;

	return p;
}

void Enqueue(List &l, int x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.last == NULL) l.first = l.last = p;
		else{
			l.last->link = p; 
			l.last = p;
		}

	}
}

int Dequeue(List &l){
    int s;
	if(l.first != NULL){
		Node *p = l.first;
		l.first = p->link;
        s = p->data;
		p->link = NULL;
		delete(p);
		if(l.first == NULL) l.last = NULL;
        return s;
	}
    cout << "Mang rong";
    exit();
}

int main(){
    
}