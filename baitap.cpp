#include<iostream>
using namespace std;
#define FAST                            ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define RW                             freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

void InputArray(int a[],int n){
	for(int i = 0; i < n; i++) cin >> a[i];
}

void OutputArray(int a[], int n){
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << "\n";
}

int LinearSearch1(int a[], int n, int x){
	for(int i = 0; i < n; i++){
		if(a[i] == x) return i;
	}
	return -1;
}

// Bai 2
int LinearSearch2(int a[], int n, int x){
	int i = 0;
	while(a[i] != x && i < n) i++;

	return i < n ? i : -1;
}

// Bai 3
int LinearSearch3(int a[], int n, int x){
	int i = 0;
	a[n] = x;
	while(a[i] != x) i++;

	return i < n ? i : -1;
}

int max(int a[], int n){
	int Index = 0;
	for(int i = 1; i < n; i++)
		if(a[Index] < a[i]) {
			Index = i;
		}
	return Index;
}

int *Max(int* a, int n){
	int *Index = a;
	for(int i = 1; i < n; i++)
		if(*Index < *(a + i)) {
			Index = (a + i);
		}
	return Index;
}

int *Max1(int* a, int n){
	int *Index = a;
	for(int *p = a; p < a + n; p++)
		if(*Index < *p) {
			Index = p;
		}
	return Index;
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

int binarySearchDQ(int a[], int x, int l, int r){
	if(r >= l){
		int mid = (r + l) / 2;

		if(a[mid] == x) return mid;
		if(a[mid] > x) return binarySearchDQ(a, x, l, mid - 1);
		if(a[mid] < x) return binarySearchDQ(a, x, mid + 1, r);
	}
    
    return -1;
}

int main(){
	FAST;RW;
	int n; cin >> n;
	int a[n];

	InputArray(a, n);
	OutputArray(a, n);

	cout << binarySearchDQ(a, 4, 0, n - 1) << "\n";

}
