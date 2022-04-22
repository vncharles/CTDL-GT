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

// them gia tri x node va dua no vo dau cua list
void push(List &l, int x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.first == NULL) {
		    l.first = p;
		    l.last = p;
		}
		else{
			p->link = l.first; 
			l.first = p;
		}

	}
}

// ham pop voi gia tri top dau tien la l.first
int pop(List &l){
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