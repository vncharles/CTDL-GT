#include<iostream>
using namespace std;

// ===========================================================
// Nhap xuat
void InputArray(int a[],int n){
	for(int i = 0; i < n; i++) cin >> a[i];
}
void OutputArray(int a[], int n){
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << "\n";
}

// ===========================================================
// Các hàm về tìm kiếm
int LinearSearch(int a[], int n, int x){
	for(int i = 0; i < n; i++){
		if(a[i] == x) return i;
	}
	return -1;
}

int binarySearch(int a[], int n, int x){
    int mid, r = n - 1, l = 0;

    while(r >= l){
    	mid = (r + l) / 2;

    	if(a[mid] == x) return mid;
    	if(a[mid] > x) r = mid - 1;
    	if(a[mid] < x) l = mid + 1;
    }

    return -1;
}

int indexMax(int a[], int n){
	int Index = 0;
	for(int i = 1; i < n; i++)
		if(a[Index] < a[i]) {
			Index = i;
		}
	return Index;
}

// ===========================================================
// Các hàm về sắp xếp
void swap(int *a, int *b){
	int tam = *a;
	*a = *b;
	*b = tam;
}

void interchangeSort(int a[], int n){
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j]) swap(a[i], a[j]);
}

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

void insertionSort(int a[], int n){
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

void bubleSort(int a[], int n){
	int fl = 1;
	for(int i = 0; i < n - 1; i++){
		fl = 1;
		for(int j = 0; j < n - i - 1; j++)
			if(a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				fl = 0;
			}
		if(fl==1) break;
	}
}

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
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){

	int n; 
	cout << "So phan tu: "; cin >> n;
	int a[n];

	cout << "Nhap cac phan tu: "; InputArray(a, n);
	cout << "Sau khi nhap: "; OutputArray(a, n);

	cout << "Max = " << a[indexMax(a, n)] << "\n";

	quickSort(a, 0, n-1);
	cout << "Mang sau khi sort: "; OutputArray(a, n);

	int search; 
	cout << "\nNhap so can tim: "; cin >> search;
	int indexx = binarySearch(a, n, search);
	if(indexx==-1) cout << "Khong tim thay " << search << " trong mang\n";
	else cout << "Tim thay " << search << " o vi tri " << indexx << "\n";

}

