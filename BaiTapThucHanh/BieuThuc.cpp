#include<iostream>
using namespace std;

struct LuyThua{
    double heSo;
    int soMu;
};

struct Node {
	LuyThua data;
	Node *link;
};

struct List {
	Node* first;
	Node* last;
};

void initList(List &l){
	l.first = l.last = NULL;
}

Node* getNode(LuyThua x){
	Node *p = new Node;
	if(p == NULL) {
		cout << "Khong du bo nho";
		exit(1);
	}
	p->data = x;
	p->link = NULL;

	return p;
}

void addLast(List &l, LuyThua x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.last == NULL) l.first = l.last = p;
		else{
			l.last->link = p; 
			l.last = p;
		}
	}
}

void inputLuyThua(List &l, int n){
    double heSo;
    int soMu;
    LuyThua lt;
    for(int i = 0; i < n; i++){
        cout << "Nhap luy thua thu " << i + 1 << "\n";
        cout << "  He so: "; cin >> heSo;
        cout << "  So mu: "; cin >> soMu;
        lt.heSo = heSo; lt.soMu = soMu;
        addLast(l, lt);
    }
}

void outputLuyThua(List l){
    Node* p = l.first;
    while(p != NULL){
        if(p != l.first){
            if(p->data.heSo > 0) cout << "+" << p->data.heSo << "x^" << p->data.soMu;
            else cout << p->data.heSo << "x^" << p->data.soMu;
        } else cout << p->data.heSo << "x^" << p->data.soMu;
        p = p->link;
    }
}

// sort
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
			if(p->data.soMu > x->data.soMu)  
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

void Sum2LuyThua(List lp, List lq, List &l){
    initList(l);
    Node *p = lp.first, *q = lq.first;
    double sum;
    LuyThua add;
    while(p&&q){
        if(p->data.soMu == q->data.soMu){
            sum = p->data.heSo + q->data.heSo;
            if(sum != 0) {
                add.heSo = sum; add.soMu = q->data.soMu;
                addLast(l, add);
            }
            p = p->link; q = q->link;
        } else {
            if(p->data.soMu > q->data.soMu){
                addLast(l, p->data);
                p = p->link;
            } else {
                addLast(l, q->data);
                q = q->link;
            }
        }
    }
    while(p){
        addLast(l, p->data);
        p = p->link;
    }
    while(q) {
        addLast(l, q->data);
        q = q->link;
    }
}

void Sum2DaThuc(List lp, List &lq){
    Node *p = lp.first, *q = lq.first;
    double sum;
    LuyThua add;
    while(p&&q){
        if(p->data.soMu == q->data.soMu){
            sum = p->data.heSo+q->data.heSo;
            if(sum) q->data.heSo = sum;
            p = p->link; q = q->link;
        } else {
            if(p->data.soMu > q->data.soMu){
                addLast(lq, p->data);
                p = p->link;
            } else {
                q = q->link;
            }
        }
    }
    while(p!=NULL){
        addLast(lq, p->data);
        p = p->link;
    }
}

void nhan1DaThuc(LuyThua x, List lt, List &l){
    LuyThua tam;
    Node* p = lt.first;
    while(p != NULL){
        tam.heSo = x.heSo * p->data.heSo;
        tam.soMu = x.soMu + p->data.soMu;
        addLast(l, tam);
        p = p->link;
    }
}

void nhan2DaThuc(List lp, List lq, List &l){
    initList(l);
    nhan1DaThuc(lp.first->data, lq, l);

    List tam; 
    Node *p = lp.first->link;
    while(p!=NULL){
        initList(tam);
        nhan1DaThuc(p->data, lq, tam);
        Sum2DaThuc(tam, l);
        quick_sort(l);
        p = p->link;
    }
}

int main(){
    List lq, lp; initList(lq);initList(lp);
    int n;

    cout << "Nhap so luong cac luy thua P: "; cin >> n;
    inputLuyThua(lp, n);
    quick_sort(lp);

    cout << "Nhap so luong cac luy thua Q: "; cin >> n;
    inputLuyThua(lq, n);
    quick_sort(lq);

    cout << "P = "; outputLuyThua(lp);
    cout << "\n";
    cout << "Q = "; outputLuyThua(lq);
    cout << "\n";

    List lsum;
    Sum2LuyThua(lp, lq, lsum);
    cout << "P + Q = "; outputLuyThua(lsum);
    cout << "\n";

    List ltich;
    nhan2DaThuc(lp, lq, ltich);
    cout << "p * Q = "; outputLuyThua(ltich); 
    
}