#include<iostream>
using namespace std;

//========================================
// Các hàm khởi tạo
struct Stuff{
    char maNV[10];
    char tenNV[20];
    double luong;
};

struct Node {
	Stuff data;
	Node *link;
};

struct List {
	Node* first;
	Node* last;
};

void initList(List &l){
	l.first = l.last = NULL;
}

Node* getNode(Stuff x){
	Node *p = new Node;
	if(p == NULL) {
		cout << "Khong du bo nho";
		exit(1);
	}
	p->data = x;
	p->link = NULL;

	return p;
}

//======================================================================
// Các hàm add
void addLast(List &l, Stuff x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.last == NULL) l.first = l.last = p;
		else{
			l.last->link = p; 
			l.last = p;
		}

	}
}

// add dành cho quick sort
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

//======================================================================
// Các hàm tìm kiếm và trả về

// tìm kiếm theo mã nhân viên rồi trả về node
Node* searchSV(List l, Stuff x){
	Node* p = l.first;
	while(p != NULL){
		if(strcmp(p->data.maNV, x.maNV) == 0) return p;
		p = p->link;
	}
	return NULL;
}

// danh sách nhân viên có lương cao nhất trả về cái list mới
List listStuffSalaryMax(List l, double maxx){
	List l_new; initList(l_new);

	Node *p = l.first;
	while(p!=NULL){
		if(p->data.luong == maxx) addLast(l_new, p->data);
		p = p->link;
	}

	return l_new;
}

// danh sách nhân viên có lương cao hơn lương trung bình
List listStuffSlaryMoreAveragSalary(List l, double tb){
	List l_new; initList(l_new);

	Node *p = l.first;
	while(p!=NULL){
		if(p->data.luong > tb) addLast(l_new, p->data);
		p = p->link;
	}

	return l_new;
}


double averageSalary(List l){
	double salary = 0;
	int count = 0;

	Node *p = l.first;
	while(p!=NULL){
		salary += p->data.luong;
		count++;
		p = p->link;
	}

	return salary/count;
}

double maxSalary(List l){
	double salary = 0;

	Node *p = l.first;
	while(p!=NULL){
		if(p->data.luong > salary)
			salary=p->data.luong;
		p = p->link;
	}
	
	return salary;
}

//==================================================================
// Các hàm xoá
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

void deleteID(List &l, char x[]){
	Node *q = l.first;
	Node *p = l.first;
	
	while(p != NULL){
		if(strcmp(l.first->data.maNV, x)==0) {
			deleteFirst(l);
			break;
		}
		if(strcmp(l.last->data.maNV, x)==0){
			deleteLast(l);
			break;
		}

		if(strcmp(p->link->data.maNV, x)==0){
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

//======================================================================
// Các hàm nhập xuất

int inputStuff(Stuff &nv){
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

void inputListStuff(List &l){
	int flag = 1;
	Stuff nv;
	while(flag){
		flag = inputStuff(nv);
		if(flag == 0) break;
		if(searchSV(l, nv) == NULL) addLast(l, nv);
	}
}

void outputListStuff(List list){
	Node *p = list.first;
	while(p != NULL){
		cout << p->data.maNV << " " << p->data.tenNV << " " << p->data.luong << "\n";
		p = p->link;
	}
}

//============================================================
// Các hàm về sắp xếp
// sắp xếp theo lương tăng dần
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

int main(){
    List listStuff;
    initList(listStuff);

	cout << "Nhap nhan vien khong trung (nhap ma 0 de dung)\n";
    inputListStuff(listStuff);

    cout << "\n=========================================================\n";
	cout << "Hiem thi danh sach\n";
    outputListStuff(listStuff);

    cout << "\n=========================================================\n";
    cout << "Cac nhan vien co luong lon hon luong TB\n";
	double average = averageSalary(listStuff);
	List list_stuff_average_salary = listStuffSlaryMoreAveragSalary(listStuff, average);
	outputListStuff(list_stuff_average_salary);

	cout << "\n=========================================================\n";
    cout << "Cac nhan vien co luong lon nhat\n";
    double salary_max = maxSalary(listStuff);
    List list_stuff_salary_max = listStuffSalaryMax(listStuff, salary_max);
    outputListStuff(list_stuff_salary_max);

	
	cout << "\n=========================================================\n";
    cout << "Sap xep luong cac nhan vien co luong cao hon TB theo thu tu tang dan\n";
    quick_sort(list_stuff_average_salary);
    outputListStuff(list_stuff_average_salary);

    cout << "\n=========================================================\n";
    char id[10]; 
    cout << "Nhap ma NV muon xoa: "; cin >> id;
    deleteID(listStuff, id);
    outputListStuff(listStuff);

    return 0;
}

