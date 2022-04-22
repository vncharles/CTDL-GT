#include<iostream>
using namespace std;

//========================================
// Các hàm khởi tạo

struct Product {
	char name[50];
	int quantity;
	double price;
};

struct Node {
	Product data;
	Node *link;
};

struct List {
	Node* first;
	Node* last;
};

void initList(List &l){
	l.first = l.last = NULL;
}

Node* getNode(Product x){
	Node *p = new Node;
	if(p == NULL) {
		cout << "Khong du bo nho";
		exit(1);
	}
	p->data = x;
	p->link = NULL;

	return p;
}

void addLast(List &l, Product x){
	Node* p = getNode(x);
	if(p != NULL){
		if(l.last == NULL) l.first = l.last = p;
		else{
			l.last->link = p; 
			l.last = p;
		}

	}
}

void inputListProduct(List &l){
    FILE *f ;
    Product p;
    f=fopen("mathang.txt","rb");
    if (f==NULL )
        cout<<"\nFILE DU LIEU KHONG TON TAI VUI LONG TAO MOI DANH SACH \n \n \n";
    else
    {
        while(fread(&p,sizeof(Product),1,f)==1)
        {
            addLast(l,p);
        }
        fclose(f);
        cout<<"\n DA NAP DU LIEU VAO BO NHO \n"    ;
    }
}

void outputListProduct(List list){
	Node *p = list.first;
	while(p != NULL){
		cout << "Ten sp: " << p->data.name;
		cout << "; So luong: " << p->data.quantity;
		cout << "; Don gia: " << p->data.price << "\n";
		p = p->link;
	}
}

List listStuffPriceMax(List l, double maxx){
	List l_new; initList(l_new);

	Node *p = l.first;
	while(p!=NULL){
		if(p->data.price == maxx) addLast(l_new, p->data);
		p = p->link;
	}

	return l_new;
}

double maxPrice(List l){
	double price= 0;

	Node *p = l.first;
	while(p!=NULL){
		if(p->data.price > price)
			price=p->data.price;
		p = p->link;
	}
	
	return price;
}

int main(){
	List listProduct;
    initList(listProduct);

    inputListProduct(listProduct);
    cout << "Danh sach product\n";
    outputListProduct(listProduct);

    double price_max = maxPrice(listProduct);
    List list_stuff_price_max = listStuffPriceMax(listProduct, price_max);
    cout << "Danh sach product co price cao nhat\n";
    outputListProduct(list_stuff_price_max);
}