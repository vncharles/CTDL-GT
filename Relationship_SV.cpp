#include<iostream>
#include <string>
#include <fstream>
using namespace std;
#define FAST                            ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define RW       						freopen("input.txt", "r", stdin);


struct SinhVien {
	char mssv[10];
	char surName[20];
	char firstName[10];
	double TK, GK, CK, DTB;
};

struct Node {
	SinhVien data;
	Node *link;
};

struct List {
	Node* first;
	Node* last;
};

void initList(List &l){
	l.first = l.last = NULL;
}

Node* getNode(SinhVien x){
	Node *p = new Node;
	if(p == NULL) {
		cout << "Khong du bo nho";
		exit(1);
	}
	p->data = x;
	p->link = NULL;

	return p;
}

Node* searchSV(List l, SinhVien x){
	Node* p = l.first;
	while(p != NULL){
		if(strcmp(p->data.mssv, x.mssv) == 0) return p;
		p = p->link;
	}
	return NULL;
}

void addLast(List &l, SinhVien x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.last == NULL) l.first = l.last = p;
		else{
			l.last->link = p; 
			l.last = p;
		}

	}
}

int inputSV(SinhVien &sv){
	// SinhVien sv;
	double tk, gk, ck, dtb;
	fflush(stdin);
	cout << "  MSSV: ";
	gets(sv.mssv);
	// char a[1] = '0';
	if(strcmp(sv.mssv, "0") == 0)
		return 0;

	fflush(stdin);
	cout << "  Ho lot: ";
	gets(sv.surName);

	fflush(stdin);
	cout << "  Ten: ";
	gets(sv.firstName);

	cout << "  Nhap diem TK, GK, CK: ";
	cin >> sv.TK >> sv.GK >> sv.CK;
	sv.DTB = (sv.TK + sv.GK + sv.CK) / 3;
	return 1;
}

void printSV(SinhVien sv){
	// cout << sv.mssv << " ";
	// cout << sv.surName << " ";
	// cout << sv.firstName << " ";
	// cout << sv.DTB << "\n";
	printf("|%9s | %-14s| %-8s|%6.2lf |\n", sv.mssv, sv.surName, sv.firstName, sv.DTB);
}

void inputArray(List &list){
	int flag = 1;
	SinhVien sv;
	while(flag){
		flag = inputSV(sv);
		if(flag && searchSV(list, sv) == NULL) addLast(list, sv);
	}
}

void outputArray(List list){
	Node *p = list.first;
	if(p != NULL) cout << "|   MSSV   |  Ho lot       |  Ten    |  DTB  |\n";
	while(p != NULL){
		printSV(p->data);
		p = p->link;
	}
}

void DTBMax(List list){
	double maxx = list.first->data.DTB;
	Node *p = list.first->link;

	while(p != NULL){
		if(p->data.DTB > maxx){
			maxx = p->data.DTB;
		}
		p = p->link;
	}
	
	p = list.first;
	if(p != NULL) cout << "|   MSSV   |  Ho lot       |  Ten    |  DTB  |\n";
	while(p != NULL){
		if(p->data.DTB == maxx)
			printSV(p->data);
		p = p->link;
	}
}

void interchangeSortDTB(List &l){
	for(Node *i = l.first; i != l.last; i = i->link)
		for(Node *j = i->link; j != NULL; j = j->link)
			if(i->data.DTB > j->data.DTB) {
				SinhVien tam = i->data;
				i->data = j->data;
				j->data = tam;
			}
}

void interchangeSortName(List &l){
	for(Node *i = l.first; i != l.last; i = i->link)
		for(Node *j = i->link; j != NULL; j = j->link)
			if(strcmp(i->data.firstName, j->data.firstName) > 0) {
				SinhVien tam = i->data;
				i->data = j->data;
				j->data = tam;
			}
}

void deleteFi(List &l){
	if(l.first != NULL){
		Node *p = l.first;
		l.first = p->link;
		p->link = NULL;
		delete(p);
		if(l.first == NULL) l.last = NULL;
	}
}

void deleteLa(List &l){
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

void deleteSV(List &l, char ma[]){
	Node *p = l.first;
	Node *q = NULL;
	while(p != NULL){
		if(strcmp(p->data.mssv, ma) == 0 && p == l.first) {
				deleteFi(l);
				break;
		}
		if(strcmp(p->data.mssv, ma) == 0 && p == l.last){
				deleteLa(l);
				break;
		}
		if(strcmp(p->link->data.mssv, ma) == 0 && p->link != NULL){
			q = p->link;
			p->link = q->link;
			delete(q);
			break;
		}
		p = p ->link;
	}
}

int main(){
	List list;
	initList(list);
	inputArray(list);
	// DTBMax(list);
	interchangeSortName(list);
	outputArray(list);
	
	char ma[10];
	cout << "Nhap ma so muon xoa: ";
	fflush(stdin);
	cin >> ma;
	deleteSV(list, ma);
	outputArray(list);

}




