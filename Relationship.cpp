#include<iostream>
#include<math.h>
#include <string>
using namespace std;
#define FAST                            ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define RW       						freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

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

// tim kiem
Node* search(List l, int x){
	Node* p = l.first;
	while(p != NULL){
		if(p->data == x) return p;
		p = p->link;
	}
	return NULL;
} 

// them gia tri x node va dua no vo dau cua list
void addFirst(List &l, int x){
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

void addLast(List &l, int x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.last == NULL) l.first = l.last = p;
		else{
			l.last->link = p; 
			l.last = p;
		}

	}
}

// them gia tri x vao sau gia tri y
void addXinY(List &l, int y, int x){
	Node *p = getNode(x);
	Node* s = search(l, y);
	if(p != NULL){
		if(l.first == NULL){
			l.first = p;
			l.last = s;
			l.first->link = s;
		} else {
			p->link = s->link;
			s->link = p;
		}
		if(l.last == s) l.last = p;
	}
}

void rmfirst(List &l){
	if(l.first != NULL){
		Node *p = l.first;
		l.first = p->link;
		p->link = NULL;
		delete(p);
		if(l.first == NULL) l.last = NULL;
	}
}

void deleteLast(List &l){
	Node *p = l.first;
	while(p != NULL){
		if(p->link != l.last){
			p = p->link;
			continue;
		}
		l.last = p;
		p = p->link;
		l.last->link = NULL;
		delete(p);
	}
	if(l.last == NULL) l.first = NULL;
}

void deletex(List &l, int x){
	Node *q = l.first;
	Node *p = l.first;
	
	while(p != NULL){
		if(l.first->data == x) {
			rmfirst(l);
			break;
		}
		if(l.last->data == x){
			deleteLast(l);
			break;
		}

		if(p->link->data == x){
			q = p->link;
			p->link = q->link;
			delete(q);
			break;
		}
		p = p->link;

		
		// if(p == l.first && p->link == NULL) {
		// 	rmfirst(l);
		// 	break;
		// }
		// if(p->link->data != x || p->link != NULL){
		// 	p = p->link;
		// 	if(p != NULL) continue;
		// }
		
		// if(p->link == l.last) {
		// 	deleteLast(l);
		// 	break;
		// } else {
		// 	q = p->link;
		// 	p->link = q->link;
		// 	delete(q);
		// 	break;
		// }
	}
	
}

void deleteAll(List &l){
	Node *p;
	while(l.first != NULL){
		p = l.first;
		l.first = p->link;
		delete(p);
	}
	l.last = NULL;
}

// Ham kiem tra nguyen to
bool checkPrime(int x){
	if(x == 2) return true;
	for(int i = 2; i < sqrt(x) + 1; i++){
		if(x % i == 0) return false;
	}
	return true;
}

void nhap(List &l){
	int n, x;
	cout << "Nhap n: "; cin >> n;
	while(n--){
		cin >> x;
		addLast(l, x);
	}
}

void printList(List l){
	Node* p = l.first;
	while(p != NULL){
		// if(checkPrime(p->data) == true)
		cout << p->data << " ";
		p = p->link;
	}
}

Node* max(List l){
	Node* maxx = l.first;
	Node* p = l.first->link;
	while(p != NULL){
		if(p->data > maxx->data) maxx = p;
		p = p->link;
	}
	return maxx;

}

Node* min(List l){
	Node* minn = l.first;
	Node* p = l.first->link;
	while(p != NULL){
		if(p->data < minn->data) minn = p;
		p = p->link;
	}
	return minn;

}

void interchangeSort(List &l){
	for(Node *i = l.first; i != l.last; i = i->link){
		for(Node *j = i->link; j != NULL; j = j->link){
			if(i->data > j->data){
				int tam = i->data;
				i->data = j->data;
				j->data = tam;
			}
		}
	}
}

int main(){
	// RW;
	List l;
	initList(l);

	nhap(l);
	// rmfirst(l);
	// deleteLast(l);
	deletex(l, 6);
	// deleteAll(l);
	// interchangeSort(l);
	printList(l);

	// cout << "\n";

	// addLast(l, 5);
	// addFirst(l, 1);
	// addXinY(l, 2, 3);
	// printList(l);


	
}













