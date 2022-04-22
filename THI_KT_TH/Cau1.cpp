#include<iostream>
#include <string.h>
using namespace std;

struct LoaiHoa{
    char maHoa[10];
    char tenHoa[20];
    double giaBan;
    int soLuong;
};

void inputHoa(LoaiHoa &hoa){
    fflush(stdin);
    cout << "  Ma hoa: "; 
    gets(hoa.maHoa);

    fflush(stdin);
    cout << "  Ten hoa: "; 
    gets(hoa.tenHoa);

    cout << "  Gia ban: "; 
    cin >> hoa.giaBan;

    cout << "  So luong: ";
    cin >> hoa.soLuong;
}

void nhapDSHoa(LoaiHoa hoa[], int n){
    for(int i = 0; i < n; i++){
        cout << "Loai hoa " << i + 1 << "\n";
        inputHoa(hoa[i]);
    }
}

void xuatDSHoa(LoaiHoa hoa[], int n){
    cout << "Ma hoa      Ten hoa                 Gia ban     So luong\n";
    cout << "==========================================================\n";
    for(int i = 0; i < n; i++){
        printf("%-12s%-16s%15.2f%13d\n", hoa[i].maHoa, hoa[i].tenHoa, hoa[i].giaBan, hoa[i].soLuong);
        // cout << hoa[i].maHoa << " " << hoa[i].tenHoa << " " << hoa[i].giaBan << " " << hoa[i].soLuong << "\n";
    }
}

int partition (LoaiHoa arr[], int low, int high)
{
    LoaiHoa pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left].giaBan < pivot.giaBan) left++;
        while(right >= left && arr[right].giaBan > pivot.giaBan) right--;
        if (left >= right) break;
        LoaiHoa tam = arr[left]; arr[left] = arr[right]; arr[right] = tam;
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(LoaiHoa arr[], int low, int high)
{
    if (low < high){
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int LinearSearch(LoaiHoa a[], int n, char tim[]){
	for(int i = 0; i < n; i++){
		if(strcmp(a[i].tenHoa, tim) == 0) return i;
	}
	return -1;
}

int main(){
    cout << "Co bao nhieu loai hoa: ";
    int n; cin >> n;
    LoaiHoa hoa[n];
    
    nhapDSHoa(hoa, n);

    cout << "a) Sắp xếp mảng theo thứ tự tăng dần theo giá bán\n";
    quickSort(hoa, 0, n-1);
    xuatDSHoa(hoa, n);

    cout << "b) Tìm kiếm một loại có tên X có trong mảng\n";
    char tim[20];
    fflush(stdin);
    cout << "Nhap ten hoa can tim: ";
    cin >> tim;
    int i = LinearSearch(hoa, n, tim);
    if(i != -1){
        cout << "Ma hoa      Ten hoa                 Gia ban     So luong\n";
        cout << "==========================================================\n";
        printf("%-12s%-16s%15.2f%13d\n", hoa[i].maHoa, hoa[i].tenHoa, hoa[i].giaBan, hoa[i].soLuong);
    } else cout << "Khong tim thay hoa";

}