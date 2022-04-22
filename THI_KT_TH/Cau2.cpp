#include<iostream>
#include <string.h>
using namespace std;

struct LoaiHoa{
    char maHoa[10];
    char tenHoa[20];
    double giaBan;
    int soLuong;
};

struct Node {
	LoaiHoa data;
	Node *link;
};

struct List {
	Node* first;
	Node* last;
};

void initList(List &l){
	l.first = l.last = NULL;
}

Node* getNode(LoaiHoa x){
	Node *p = new Node;
	if(p == NULL) {
		cout << "Khong du bo nho";
		exit(1);
	}
	p->data = x;
	p->link = NULL;

	return p;
}

Node* searchHoa(List l, LoaiHoa x){
	Node* p = l.first;
	while(p != NULL){
		if(strcmp(p->data.maHoa, x.maHoa) == 0) return p;
		p = p->link;
	}
	return NULL;
}

void addLast(List &l, LoaiHoa x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.last == NULL) l.first = l.last = p;
		else{
			l.last->link = p; 
			l.last = p;
		}

	}
}

int inputHoa(LoaiHoa &hoa){
    fflush(stdin);
    cout << "  Ma hoa: "; 
    gets(hoa.maHoa);

    if(strcmp(hoa.maHoa, "0") == 0) return 0;

    fflush(stdin);
    cout << "  Ten hoa: "; 
    gets(hoa.tenHoa);

    cout << "  Gia ban: "; 
    cin >> hoa.giaBan;

    cout << "  So luong: ";
    cin >> hoa.soLuong;
    return 1;
}

void inputArray(List &l){
	int flag = 1, count = 1;
	LoaiHoa hoa;
	while(flag){
        cout << "Nhap loai hoa thu " << count << "\n";
		flag = inputHoa(hoa);
		if(flag && searchHoa(l, hoa) == NULL) {
            addLast(l, hoa);
            count++;
        }
        if(flag == 0) break;
	}
}

void outputArray(List list){
	Node *p = list.first;
    cout << "Ma hoa      Ten hoa                 Gia ban     So luong\n";
    cout << "==========================================================\n";
	while(p != NULL){
        printf("%-12s%-16s%15.2f%13d\n", p->data.maHoa, p->data.tenHoa, p->data.giaBan, p->data.soLuong);
		// cout << p->data.maHoa << " " << p->data.tenHoa << " " << p->data.giaBan << " " << p->data.soLuong <<  "\n";
		p = p->link;
	}
}

double Min(List l){
	double minn = l.first->data.giaBan;
	Node* p = l.first->link;
	while(p != NULL){
		if(p->data.giaBan < minn) minn = p->data.giaBan;
		p = p->link;
	}
	return minn;

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
			if(p->data.soLuong <= x->data.soLuong)  
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

List HoaThap(List l, double Min){
	List l_new; initList(l_new);

	Node *p = l.first;
	while(p!=NULL){
		if(p->data.giaBan == Min) addLast(l_new, p->data);
		p = p->link;
	}

	return l_new;
}

int main(){
    List l;
    initList(l);

	cout << "a) Nhập vào một loại hoa không trùng với các loại hoa đã có trong danh sách (Nhap ma 0 de dung)\n";
    inputArray(l);

	cout << "b) Hiển thị thông tin loại hoa.\n";
    outputArray(l);

	double minn = Min(l);
	List l_new = HoaThap(l, minn);
	cout << "c) In thông tin của loại hoa có giá thấp nhất\n";
	outputArray(l_new);

	
	quick_sort(l_new);
	cout << "d) Tách các loại hoa có giá bán thấp nhất thành một danh sách và sắp xếp danh sách đó theo thứ tự tăng dần theo số lượng\n";
    outputArray(l_new);

    return 0;

}