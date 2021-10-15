#include<iostream>
#include <string>
using namespace std;
#define FAST                            ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define RW                             freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

void swap(int *a, int *b){
	int tam = *a;
	*a = *b;
	*b = tam;
}


// Sap xep tang dan dua min ve dau
void interchangeSort(int a[], int n){
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j]) swap(a[i], a[j]);
}


// Sap xep tang dan dua max ve cuoi
void interchangeSort2(int a[], int n){
	for(int i = n - 1; i > 0; i--)
		for(int j = 0; j < i - 1; j++)
			if(a[i] < a[j]) swap(a[i], a[j]);
}


// Sap xep giam dan dua max ve cuoi
void interchangeSort3(int a[], int n){
	for(int i = n - 1; i > 0; i--)
		for(int j = 0; j <= i - 1; j++)
			if(a[i] > a[j]) swap(a[i], a[j]);
}


// Sap xep giam dan dua min ve cuoi
void interchangeSort4(int a[], int n){
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] < a[j]) swap(a[i], a[j]);
}


// Sap xep tang dan dua min ve dau
void selectionSort(int a[],int n){
	int Index = 0;
	for(int i = 0; i < n - 1; i++){
		Index = i;
		for(int j = i + 1; j < n; j++){
			if(a[Index] > a[j]) Index = j;
		}
		if(Index != i) swap(&a[Index], &a[i]);
	}
}


// Sap xep tang dan dua max ve cuoi
void selectionSort2(int a[],int n){
	int Index;
	for(int i = n - 1; i > 0; i--){
		Index = i;
		for(int j = 0; j <= i - 1; j++)
			if(a[j] > a[Index]) Index = j;

		if(Index != i) swap(&a[Index], &a[i]);
	}
}

// giam dan dua max ve dau
void selectionSort3(int a[],int n){
	int Index = 0;
	for(int i = 0; i < n - 1; i++){
		Index = i;
		for(int j = i + 1; j < n; j++){
			if(a[Index] < a[j]) Index = j;
		}
		if(Index != i) swap(&a[Index], &a[i]);
	}
}

// giam dan dua min ve cuoi
void selectionSort4(int a[],int n){
	int Index;
	for(int i = n - 1; i > 0; i--){
		Index = i;
		for(int j = 0; j <= i - 1; j++)
			if(a[j] < a[Index]) Index = j;

		if(Index != i) swap(&a[Index], &a[i]);
	}
}

// tang dan

void insertionSort1(int a[], int n){
	int pos, value;
	for(int i = 1; i < n; i++){
		pos = i;
		value = a[i];
		while(pos > 0 && a[pos-1] > value){
			a[pos] = a[pos - 1];
			pos--;
		}
		a[pos] = value;
	}
}

// giam dan
void insertionSort2(int a[], int n){
	int pos, value;
	for(int i = 1; i < n; i++){
		pos = i;
		value = a[i];
		while(pos > 0 && a[pos-1] < value){
			a[pos] = a[pos - 1];
			pos--;
		}
		a[pos] = value;
	}
}


// tăng dần đưa giấ trị lớn nhất về cuối
void bubleSort1(int a[], int n){
	int fl = 1;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++)
			if(a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				fl = 0;
			}
		if(fl) break;
	}
}


// giảm dần đưa giá trị bé nhất về cuối
void bubleSort3(int a[], int n){
	int fl = 1;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++)
			if(a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
				fl = 0;
			}
		if(fl) break;
	}
}

struct SinhVien{
	char mssv[10];
	char lastname[20];
	char firstname[10];
	float TK, GK, CK, DTB;
};

void inputSV(SinhVien ds[], int n){
	float tk, gk, ck;
	for(int i = 0; i < n; i++) {
		cout << "Nhap sinh vien thu " << i + 1 << "\n";
		fflush(stdin);
		cout << "  MSSV: ";
		cin >> ds[i].mssv;
		fflush(stdin);
		cout << "  Ho va lot: ";
		cin.getline(ds[i].lastname, 20);
		fflush(stdin);
		cout << "  Ten: ";
		cin >> ds[i].firstname;
		cout << "  Diem TK GK CK: ";
		cin >> tk >> gk >> ck;
		ds[i].TK = tk; ds[i].CK = ck; ds[i].GK = gk; ds[i].DTB = (tk + gk + ck) / 3;
	}
}

void outputSV(SinhVien ds[], int n){
	cout << "DANH SACH SINH VIEN\n";
	cout << "+--------------------------------------+\n";
	cout << "|   MSSV   |     Ho va ten     |  DTB  |\n";
	cout << "+--------------------------------------+\n";
	char name[30];
	for(int i = 0; i < n; i++){
		// cout << ds[i].mssv << "\n";	
		// cout << ds[i].name << "\n";
		// cout << ds[i].TK << " " << ds[i].GK << " " << ds[i].CK << "\n";
		// cout << ds[i].DTB << "\n";
		// cout << "----------------\n";
		strcpy(name, ds[i].lastname);
		strcat(name, ds[i].firstname);
		printf("|%9s | %-18s| %-6.2f|\n", ds[i].mssv, name, ds[i].DTB);
		cout << "+--------------------------------------+\n";
	}
}

void bubleSortDTB(SinhVien a[], int n){
	int fl = 1;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++)
			if(a[j].DTB > a[j + 1].DTB) {
				swap(a[j], a[j + 1]);
				fl = 0;
			}
		if(fl) break;
	}
}

void bubleSortName(SinhVien a[], int n){
	int fl = 1;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++)
			if(a[j].DTB > a[j + 1].DTB) {
				swap(a[j], a[j + 1]);
				fl = 0;
			}
		if(fl) break;
	}
}

// QuickSort
int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
void quickSort(NhanVien arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
	// FAST;RW;
	int n; 
	cout << "Nhap so luong SV: "; cin >> n;
	SinhVien ds[n]; 

	inputSV(ds, n);
	bubleSortDTB(ds, n);
	outputSV(ds, n);
}

