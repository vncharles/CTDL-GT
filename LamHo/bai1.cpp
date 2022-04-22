#include <iostream>
using namespace std;

struct TINH {
	char name[30];
	double area;
	int population;

};

void swap(TINH *a, TINH *b){
	TINH tam = *a;
	*a = *b;
	*b = tam;
}

void bubleSort(TINH *arr, int length){
	int fl = 1;
	for(int i = 0; i < length - 1; i++){
		fl = 1;
		for(int j = 0; j < length - i - 1; j++)
			if((arr+j)->population < (arr+j+1)->population) {
				swap(arr+j, arr+j+1);
				fl = 0;
			}
		if(fl==1) break;
	}
}

// void nhap(TINH *arr, int length){
// 	FILE *input;
// 	input = fopen("tinh.txt", "r");
// 	if (input == NULL) {
// 	printf("Khong co du lieu");
// 	exit (0);
// 	}

// 	for(int i = 0; i < length; i++){
// 		cout << "Ten: ";
// 		fflush(stdin);
// 		gets((arr+i)->name);
// 		cout << "Dien tich: ";
// 		cin >> (arr+i)->area;
// 		cout << "Dan so: ";
// 		cin >> (arr+i)->population;
// 	}
// }

void xuat(TINH *arr, int length){
	for(int i = 0; i < length; i++){
		cout << "Ten: " << (arr+i)->name;
		cout << "; Dien tich: " << (arr+i)->area;
		cout << "; Dan so: " << (arr+i)->population << "\n";
	}
}

int main(){
	int length;
	cout << "Nhap so tinh: "; cin >> length;
	TINH *arr = new TINH[length];

	// nhap(arr, length);
	cout << "Danh sach chua sort\n";
	xuat(arr, length);

	bubleSort(arr, length);
	cout << "Danh sach sau khi sort\n";
	xuat(arr, length);
}