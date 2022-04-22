#include <iostream>
using namespace std;

// =====================================
// Các hàm khởi tạo cây
struct Date{
    int day, month, year;
};

struct Order{
    char ID[10], address[100];
    int status, SL;
    Date receivedDate, deliveryDate;
};

struct TNode {
    Order data;
    TNode *left;
    TNode *right;
};

TNode *getTNode(Order o) {
    TNode *p = new TNode;
    p->data = o;
    p->left = NULL;
    p->right = NULL;
    return p;
}

typedef TNode* Tree;

void initTree(Tree &T) {
    T = NULL;
}

// =========================================
// Các hàm xử lí nhập cây
void addTNode(Tree &od, Order o) {
    if(od) {
        if (strcmp(od->data.ID, o.ID) == 0) return;
        if (strcmp(od->data.ID, o.ID) > 0) addTNode(od->left, o);
        else addTNode(od->right, o);
    } else od = getTNode(o);
}

void createTree(Tree &od){
    Date receivedDate, deliveryDate;
    Order o;
    int day, month, year;
    while(true){
        cout << "=========================================================\n";
        cout << "Ma don hang(finish->thoat): "; cin >> o.ID;
        if(strcmp(o.ID, "finish") == 0) break;

        cout << "Nhap ngay nhan: "; scanf("%d/%d/%d", &day, &month, &year);
        receivedDate.day = day; receivedDate.month = month; receivedDate.year = year;
        o.receivedDate = receivedDate;

        cout << "Nhap ngay giao: "; scanf("%d/%d/%d", &day, &month, &year);
        deliveryDate.day = day; deliveryDate.month = month; deliveryDate.year = year;
        o.deliveryDate = deliveryDate;

        fflush(stdin);
        cout << "Nhap dia chi: ";
        gets(o.address);

        cout << "So luong: "; cin >> o.SL;

        cout << "Trang thai(1.Da giao; 0.Chua giao): "; cin >> o.status; 

        addTNode(od, o);
    }
}

//================================
// cac ham ve xuat va xu li tree
void LNR(Tree T) {
    if(T) {
        LNR(T->left);
        cout << T->data.ID << " ";
        LNR(T->right);
    }
}

void outputOneOrder(Order o){
    char status[10];
    o.status ? strcpy(status, "Da giao") : strcpy(status, "Chua giao");
    printf("%-7s|   %02d/%02d/%04d   |   %02d/%02d/%04d   | %-45s|%9d | %8s\n", o.ID, o.receivedDate.day, o.receivedDate.month, o.receivedDate.year,
                                                                    o.deliveryDate.day, o.deliveryDate.month, o.deliveryDate.year,
                                                                    o.address, o.SL, status);

}



//=========================================================
// Tìm kiếm thống kê
// tìm kiếm theo ID và xuất ra luôn
void findID(Tree od, char id[]){
    if(od) {
        if (strcmp(od->data.ID, id) == 0){
            outputOneOrder(od->data);
            exit(0);
        }
        if (strcmp(od->data.ID, id) > 0)
            findID(od->left, id);
        else findID(od->right, id);
    }
    if(od == NULL) cout << "Khong tim thay\n";
}

//tim kiem maDH theo vòng while trả về TNode
TNode *searchID(Tree t, char ma[]){
    TNode *p = t;
    while(p){
        if (strcmp(t->data.ID, ma)==0)
            return p;
        if (strcmp(t->data.ID, ma)>0)
            p = p->left;
        else p = p->right;
    }
    return NULL;
}

//So luong don hang theo loai(1: giao thanh cong// 0 : giao khong thanh cong)
int GiaoHang(Tree t, int loai){
    if(!t) return 0;
    if(t->data.status == loai)
        return 1 + GiaoHang(t->left, loai) + GiaoHang(t->right, loai);
    return GiaoHang(t->left, loai) + GiaoHang(t->right, loai);
}

void donHangThangX(Tree od, Tree &thangX, int t){
    if(od){
        if(od->data.deliveryDate.month == t && od->data.status == 1)
            addTNode(thangX, od->data);
        donHangThangX(od->left, thangX, t);
        donHangThangX(od->right, thangX, t);
    }
}

void donHangGV(Tree t, Tree &gv){
    if(t){
        if(strstr(t->data.address, "Go Vap") && t->data.status == 1)
            addTNode(gv, t->data);
        donHangGV(t->left, gv);
        donHangGV(t->right, gv);
    }
}

int MAX = INT_MIN; // gán cho biến MAX là giá trị nhỏ nhất của kiểu integer
//// hàm tìm phần tử lớn nhất trong cây
void findMax(Tree t){
    if (t != NULL){
        // xử lí
        if (MAX < t->data.SL)
            MAX = t->data.SL; // cập nhật lại giá trị cho biến MAX
        findMax(t->left);
        findMax(t->right);
    }
} // lấy về tree maxx dánh sách đơn hàng có SL max
void donHangMax(Tree od, Tree &maxx){
    if(od) {
        donHangMax(od->left, maxx);
        if(od->data.SL == MAX) addTNode(maxx, od->data);
        donHangMax(od->right, maxx);
    } 
}

// ==============================================================
// Các hàm xử lí

// Huy mot phan tu
void searchStandFor(Tree &p, Tree &q){
    if(q->left)
        searchStandFor(p, q->left);
    else {
        p->data = q->data;
        p = q;
        q = q->right;
    }
}
void delNode(Tree &root, char x[]){
    if(root == NULL) return;
    if(strcmp(root->data.ID, x) > 0) return delNode(root->left, x);
    if(strcmp(root->data.ID, x) < 0) return delNode(root->right, x);

    TNode* p = root;
    if(root->left == NULL)
        root = root->right;
    else if(root->right == NULL)
        root = root->left;
    else searchStandFor(p, root->right);
    delete p;
}

// xoa cac node chua giao hang
void delStatus0(Tree &root){
    if(root){
        delStatus0(root->left);
        delStatus0(root->right);
        if(root->data.status==0){
            TNode* p = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            else searchStandFor(p, root->right);
            delete p;
        }
    }
}

//delete all
void deleteTree(node* node){
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
     
    delete node;
}

//tong SL
int sum(Tree T) {
    if(T == NULL) return 0;
    return T->data.SL + sum(T->left) + sum(T->right);
}

// dem so NODE
int Count(Tree T) {
    if(T == NULL) return 0;
    return 1 + Count(T->left) + Count(T->right);
}

// xuat cay
void display(Tree T) {
    if(T){
        display(T->left);
        outputOneOrder(T->data);
        display(T->right);
    }
}

//in cac don co SL lon hon SL trung binh
void display1(Tree T, int tb) {
    if(T){
        display1(T->left, tb);
        if(T->data.SL>tb)
            outputOneOrder(T->data);
        display1(T->right, tb);
    }
}

int main(){
    Tree od;
    initTree(od);
    createTree(od);

    // cout << "======================================================================================================================\n";
    // char id[10];
    // cout << "Nhap ma don can tim: "; cin >> id;
    // TNode* t = searchID1(od, id);
    // if(t == NULL) cout << "Khong tim thay\n";
    // else outputOneOrder(t->data);

    // cout << "======================================================================================================================\n";
    // cout << "Tong don hang (0. Chua giao; 1. Da giao): ";
    // int loai; cin >> loai;
    // cout << "So luong don la: " << GiaoHang(od, loai);

    // cout << "======================================================================================================================\n";
    // cout << "Nhap thang muon xem: ";
    // int t; cin >> t;
    // Tree dhThang; initTree(dhThang);
    // donHangThangX(od, dhThang, t);
    // if(dhThang != NULL){
    //     cout << "Ma don | Ngay nhan hang | Ngay giao hang | Dia chi                                      | So luong | Trang thai\n";
    //     cout << "----------------------------------------------------------------------------------------------------------------\n";
    //     display(dhThang);
    // }

    // cout << "======================================================================================================================\n";
    // cout << "Don hang giao thanh cong go vap\n";
    // Tree dhGV;initTree(dhGV);
    // donHangGV(od, dhGV);
    // if(dhGV != NULL){
    //     cout << "Ma don | Ngay nhan hang | Ngay giao hang | Dia chi                                      | So luong | Trang thai\n";
    //     cout << "----------------------------------------------------------------------------------------------------------------\n";
    //     display(dhGV);
    // }

    // cout << "======================================================================================================================\n";
    // cout << "Cac don hang co so luong lon nhat\n";
    // Tree dhMax; initTree(dhMax);
    // findMax(od);
    // donHangMax(od, dhMax);
    // if(dhMax != NULL){
    //     cout << "Ma don | Ngay nhan hang | Ngay giao hang | Dia chi                                      | So luong | Trang thai\n";
    //     cout << "----------------------------------------------------------------------------------------------------------------\n";
    //     display(dhMax);
    // }

    // LNR(od);
    // char tim[10];
    // cout << "\nNhap ma muon xoa: "; cin >> tim;
    // delNode(od);
    // LNR(od);

    // int tb = sum(od)/Count(od);
    // cout << tb << "\n";
    // display1(od, tb);
}