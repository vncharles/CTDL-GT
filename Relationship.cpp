#include<iostream>
#include<math.h>
#include <string>
using namespace std;


// khởi tạo
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

// các hàm thêm node
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

// các hàm về xoá node
void deleteFirst(List &l){
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
			deleteFirst(l);
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


// xủ lí nhập xuất
void nhap(List &l){
	int x;
	while(true){
		cin >> x;
		if(x == -1) break;
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


// tìm max
Node* max(List l){
	Node* maxx = l.first;
	Node* p = l.first->link;
	while(p != NULL){
		if(p->data > maxx->data) maxx = p;
		p = p->link;
	}
	return maxx;

}
// tìm min
Node* min(List l){
	Node* minn = l.first;
	Node* p = l.first->link;
	while(p != NULL){
		if(p->data < minn->data) minn = p;
		p = p->link;
	}
	return minn;

}

// Quick sort
void addFirstQS(List &l, Node *p){
	// Node* p = getNode(x);
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
void quick_sort(List &l) {        
	List l1, l2;  
	if(l.first==NULL) return;  
	initList(l1);  
	initList(l2);  
	Node *x=l.first;  
	l.first = x->link;  
	while(l.first!=NULL){  
			Node *p=l.first;  
			l.first = p->link;  
			p->link = NULL;  
			if(p->data <= x->data)  
					addFirstQS(l1,p);  
			else  
					addFirstQS(l2,p);  
	}  
	quick_sort(l1);  
	quick_sort(l2);  
	if(l1.first==NULL)  
			l.first=x;  
	else  {  
		l.first = l1.first;  
		l1.last->link = x;  
	}  
	x->link = l2.first;  

	if(l2.first==NULL)  
		l.last = x;  
	else {  
		l.last = l2.last;  
	}  
}  


int main(){
	
	List l;
	initList(l);

	// nhap(l);
	// rmfirst(l);
	// deleteLast(l);
	// deletex(l, 6);
	// deleteAll(l);
	// interchangeSort(l);
	addLast(l, 5);
	addLast(l, 2);
	addLast(l, 4);
	addLast(l, 1);
	addLast(l, 8);
	addLast(l, 7);
	quick_sort(l);
	printList(l);

	// cout << "\n";

	// addLast(l, 5);
	// addFirst(l, 1);
	// addXinY(l, 2, 3);
	// printList(l);


	
}













