#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

struct NgayThang{
    int ngay;
    int thang;
    int nam;
};

void nhapngaythang(NgayThang &nt){
     cout<<"   Nhap ngay giao (dd/mm/yyyy): ";
        scanf("%d %d %d", &nt.ngay, &nt.thang, &nt.nam);
}

struct DonHang{
   char MaDH[10];
   NgayThang ngaynhan;
   NgayThang ngaygiao;
   char diachi[50];
   int trangthai;
};

struct Node{
    DonHang data;
    Node *left;
    Node *right;
};

void inDH(DonHang dh){
    printf("%-5s | %2d/%2d/%4d | %2d/%2d/%4d | %-30s | %-10s\n",
        dh.MaDH, dh.ngaygiao.ngay, dh.ngaygiao.thang, dh.ngaygiao.nam,
        dh.ngaynhan.ngay, dh.ngaynhan.thang, dh.ngaynhan.nam, dh.diachi,
        (dh.trangthai)?"Da giao":"Chua giao");
}

typedef Node *Tree;

Node *CreateNode(DonHang dh)
{
    Node *p = new Node;
    p->data = dh;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int AddNode(Tree &T, DonHang x){
    if (T) {
        if (T->data.MaDH == x.MaDH)
            return 0;
        if (x.MaDH > T->data.MaDH)
            AddNode(T->right, x);
        else    
            AddNode(T->left, x);
    }
    else
        T = CreateNode(x);
    return 1;
}

void CreateTree(Tree &t)
{
    int n, x;
    cout<<"Nhap sl don hang: ";
    cin>>n;
    DonHang dh;
    for (int i = 0; i < n; i++){
        cout<<"DH"<<i<<" :"<<endl;
        cout<<"   Nhap MaDH don hang: ";
        cin>>dh.MaDH;
        nhapngaythang(dh.ngaygiao);
        nhapngaythang(dh.ngaynhan);
        cout<<"   Nhap dia chi: ";
        fflush(stdin);
        gets(dh.diachi);
        cout<<"   Nhap trang thai don hang (0/1): ";
        cin>>dh.trangthai;
        if (!AddNode(t, dh))
            cout<<"ma hang da ton tai!!";
        cout<<endl;
    }
}

void LNR(Tree t){
    if (t){
        LNR(t->left);
        inDH(t->data);
        LNR(t->right);
    }
}

//tim kiem theo maDH theo huong de quy
Node *find(Tree t, char MaDH[]){
    if (t)
    {
        if (strcmp(t->data.MaDH,MaDH)==0)
            return t;
        if (strcmp(t->data.MaDH,MaDH)>0)
            return find(t->left, MaDH); 
        return find(t->right, MaDH); 
    }
    return NULL;
}

//tim kiem maDH theo vòng while
Node *find2(Tree t, char ma[]){
    Node *p = t;
    while (p){
        if (strcmp(t->data.MaDH,ma)==0)
            return p;
        if (strcmp(t->data.MaDH,ma)>0)
            p = p->left;
        else    
            p = p->right;
    }
    return NULL;
}

//So luong don hang theo loai(1: giao thanh cong// 0 : giao khong thanh cong)
int GiaoHang(Tree t, int loai){
    if (!t)
        return 0;
    if (t->data.trangthai)
        return 1 + GiaoHang(t->left, loai) + GiaoHang(t->right, loai);
    else    
        return GiaoHang(t->left, loai) + GiaoHang(t->right, loai);
}

// int GiaoKhongThanhCong(Tree t){
//     if (!t)
//         return 0;
//     if (!t->data.trangthai)
//         return 1 + GiaoKhongThanhCong(t->left) + GiaoKhongThanhCong(t->right);
//     else    
//         return GiaoKhongThanhCong(t->left) + GiaoKhongThanhCong(t->right);
// }

void donHangGiaoThanhCongoGV(Tree t){
    if (t){
        donHangGiaoThanhCongoGV(t->left);
        if (t->data.trangthai && strcmp(t->data.diachi, "Go Vap") == 0)
            inDH(t->data);
        donHangGiaoThanhCongoGV(t->right);
    }
}

// void donHangGiaoThanhCong(Tree t, char diaChi[]){
//     if (t){
//         donHangGiaoThanhCong(t->left, diaChi);
//         if (t->data.trangthai && strstr(t->data.diachi, diaChi)!=NULL)
//             inDH(t->data);
//         donHangGiaoThanhCong(t->right, diaChi);
//     }
// }

// void donHangGiaoKhongThanhCong(Tree t){
//     if (t){
//         donHangGiaoKhongThanhCong(t->left);
//         if (!t->data.trangthai)
//             inDH(t->data);
//         donHangGiaoKhongThanhCong(t->right);
//     }
// }

//so luong don hang giao thanhcong(khongthanhcong) ở tháng m năm y
int Dem(Tree t, int loai, int m, int y){
    if (t==NULL)
        return 0;
    if (t->data.trangthai == loai && t->data.ngaygiao.thang == m && t->data.ngaygiao.nam == y)
        return 1 + Dem(t->left, loai, m, y) + Dem(t->right, loai, m, y);
    else
        return Dem(t->left, loai, m, y) + Dem(t->right, loai, m, y); 
}



int main(){
    Tree t;
    t = NULL;
    CreateTree(t);
    LNR(t);
    cout<<endl;
    // cout<<"Co: "<<GiaoThanhCong(t)<<" don hang giao thanh cong"<<endl;
    // cout<<"Co: "<<GiaoKhongThanhCong(t)<<" don hang giao khong thanh cong"<<endl;
    // donHangGiaoThanhCong(t);
    // cout<<endl;
    // donHangGiaoKhongThanhCong(t);
    // cout<<endl;
    // cout<<"Nhap thang can thong ke: ";
    // int th;
    // cin>>th;
    // GiaoThanhCongThangX(t, th);

    // cout<<endl<<"Nhap MaDH don hang can tim: ";
    // int x, y;
    // cin>>x>>y;
        
    //     cout<<Dem(t, x, y);
    donHangGiaoThanhCongoGV(t);
    
}
