#include<iostream>
using namespace std;

struct NhanVien{
    char maNV[10];
    char tenNV[20];
    double luong;
};

void inputNV(NhanVien &nv){
    fflush(stdin);
    cout << "  Ma nhan vien: "; 
    gets(nv.maNV);

    fflush(stdin);
    cout << "  Ten nhan vien: "; 
    gets(nv.tenNV);

    cout << "  Luong nhan vien: "; 
    // double tienLuong;
    cin >> nv.luong;
}

void nhapDSNV(NhanVien nv[], int n){
    for(int i = 0; i < n; i++){
        cout << "Sinh vien " << i + 1 << "\n";
        inputNV(nv[i]);
    }
}

void xuatDSNV(NhanVien nv[], int n){
    for(int i = 0; i < n; i++){
        cout << nv[i].maNV << " " << nv[i].tenNV << " " << nv[i].luong << "\n";
    }
}

int partition (NhanVien arr[], int low, int high)
{
    NhanVien pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left].luong > pivot.luong) left++;
        while(right >= left && arr[right].luong < pivot.luong) right--;
        if (left >= right) break;
        NhanVien tam = arr[left]; arr[left] = arr[right]; arr[right] = tam;
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(NhanVien arr[], int low, int high)
{
    if (low < high){
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

NhanVien LinearSearch1(NhanVien a[], int n, char x[]){
	for(int i = 0; i < n; i++)
		if(strcmp(a[i].maNV, x) == 0) return a[i];
}

int main(){
    cout << "So nhan vien: ";
    int n; cin >> n;
    NhanVien nv[n];
    
    nhapDSNV(nv, n);

    quickSort(nv, 0, n-1);

    char ma[10];
    fflush(stdin);
    cout << "nhap ma muon tim: "; cin >> ma;
    NhanVien nv1 = LinearSearch1(nv, n, ma);
    cout << nv1.maNV << " " << nv1.tenNV << " " << nv1.luong << "\n";

    xuatDSNV(nv, n);
}