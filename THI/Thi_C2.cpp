#include<iostream>
#include <string.h>
using namespace std;

struct NhanVien{
    char maNV[10];
    char tenNV[20];
    double luong;
};

struct Node {
	NhanVien data;
	Node *link;
};

struct List {
	Node* first;
	Node* last;
};

void initList(List &l){
	l.first = l.last = NULL;
}

Node* getNode(NhanVien x){
	Node *p = new Node;
	if(p == NULL) {
		cout << "Khong du bo nho";
		exit(1);
	}
	p->data = x;
	p->link = NULL;

	return p;
}

Node* searchSV(List l, NhanVien x){
	Node* p = l.first;
	while(p != NULL){
		if(strcmp(p->data.maNV, x.maNV) == 0) return p;
		p = p->link;
	}
	return NULL;
}

void addLast(List &l, NhanVien x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.last == NULL) l.first = l.last = p;
		else{
			l.last->link = p; 
			l.last = p;
		}

	}
}

int inputNV(NhanVien &nv){
    fflush(stdin);
    cout << "  Ma nhan vien: "; 
    gets(nv.maNV);

    if(strcmp(nv.maNV, "0") == 0) return 0;

    fflush(stdin);
    cout << "  Ten nhan vien: "; 
    gets(nv.tenNV);

    cout << "  Luong nhan vien: "; 
    // double tienLuong;
    cin >> nv.luong;
    return 1;
}

void inputArray(List &l){
	int flag = 1;
	NhanVien nv;
	while(flag){
		flag = inputNV(nv);
		if(flag && searchSV(l, nv) == NULL) addLast(l, nv);
        if(flag == 0) break;
	}
}

// void printNV(NhanVien x){
//     cout << 
// }

void outputArray(List list){
	Node *p = list.first;
	while(p != NULL){
		cout << p->data.maNV << " " << p->data.tenNV << " " << p->data.luong << "\n";
		p = p->link;
	}
}

// quick sort
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
			if(p->data.luong <= x->data.luong)  
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

double luongTB(List l){
	double luong = 0;
	int count = 0;

	Node *p = l.first;
	while(p!=NULL){
		luong += p->data.luong;
		count++;
		p = p->link;
	}
	return luong/count;
}

List NVCaoHonLuongTB(List l, double tb){
	List l_new; initList(l_new);

	Node *p = l.first;
	while(p!=NULL){
		if(p->data.luong > tb) addLast(l_new, p->data);
		p = p->link;
	}

	return l_new;
}

int main(){
    List l;
    initList(l);

	cout << "a) Nhap nhan vien khong trung (nhap ma 0 de dung)\n";
    inputArray(l);

	cout << "b) Hiem thi danh sach\n";
    outputArray(l);

	double tb = luongTB(l);
	List l_new = NVCaoHonLuongTB(l, tb);
	cout << "c) Cac nhan vien co luong lon hon luong TB\n";
	outputArray(l_new);

	
	quick_sort(l_new);
	cout << "d) Sap xep cac nhan vien co luong lon hon luong TB\n";
    outputArray(l_new);

    return 0;
}