#include <iostream>
using namespace std;


// khoi tao struct va tree
struct EMPLOYEE {
    char ID[10], name[20];
    double salary, bonus;
};

struct TNode {
    EMPLOYEE data;
    TNode *left;
    TNode *right;
};

TNode *getTNode(EMPLOYEE e) {
    TNode *p = new TNode;
    p->data = e;
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
void addTNode(Tree &ep, EMPLOYEE e) {
    if(ep) {
        if (strcmp(ep->data.ID, e.ID) == 0) return;
        if (strcmp(ep->data.ID, e.ID) > 0) addTNode(ep->left, e);
        else addTNode(ep->right, e);
    } else ep = getTNode(e);
}

void addTNodeSalary(Tree &ep, EMPLOYEE e) {
    if(ep) {
        if (ep->data.salary < e.salary) addTNodeSalary(ep->left, e);
        else addTNodeSalary(ep->right, e);
    } else ep = getTNode(e);
}

void createTree(Tree &ep){
    EMPLOYEE e;
    cout << "=========================================================\n";
    cout << "Ma nhan vien: "; cin >> e.ID;

    fflush(stdin);
    cout << "Ten nhan vien: "; gets(e.name);

    cout << "Luong: "; cin >> e.salary;

    cout << "Thuong: "; cin >> e.bonus;

    addTNode(ep, e);
}

// =========================================
// cac ham xuat cay
void output(EMPLOYEE e){
    cout <<  "Ma nhan vien: " <<  e.ID << "\n";
    cout << "  Ten: " << e.name << "\n";
    cout << "  Luong: " << e.salary << "\n";
    cout << "  Thuong: " << e.bonus << "\n";
}

void display(Tree ep) {
    if(ep){
        display(ep->left);
        output(ep->data);
        display(ep->right);
    }
}

// =========================================
// cac ham xu li
double MAX = 0;
void findMax(Tree t){
    if (t != NULL){
        // xử lí
        if (MAX < t->data.bonus)
            MAX = t->data.bonus; // cập nhật lại giá trị cho biến MAX
        findMax(t->left);
        findMax(t->right);
    }
}
void thongKeBonusMax(Tree ep){
    if(ep) {
        thongKeBonusMax(ep->left);
        if(ep->data.bonus == MAX) output(ep->data);
        thongKeBonusMax(ep->right);
    } 
}


//tong salary
int sum(Tree T) {
    if(T == NULL) return 0;
    return T->data.salary + sum(T->left) + sum(T->right);
}

// dem so nhan vien
int Count(Tree T) {
    if(T == NULL) return 0;
    return 1 + Count(T->left) + Count(T->right);
}

// ham xuat ra cac nhan vien co luong cao hon luong tb
void salaryLon(Tree ep, Tree &ep_new, double tb){
    if(ep) {
        salaryLon(ep->left, ep_new, tb);
        if(ep->data.salary > tb) addTNodeSalary(ep_new, ep->data);
        salaryLon(ep->right, ep_new, tb);
    } 
}

int menu(){
    cout << "1. Them nhan vien\n";
    cout << "2. Hiem thi danh sach nhan vien\n";
    cout << "3. Thong ke nhan vien co tien thuong cao nhat\n";
    cout << "4. Danh sach co luong cao hon luong trung binh\n";
    cout << "0. Exit\n";

    int choice;
    cout << "Moi ban chon: "; cin >> choice;

    return choice;
}

int main() {
    Tree ep; initTree(ep);

    int choice;

    do {
        choice = menu();
        switch(choice){
            case 0:
                cout << "Chao tam biet va hen gap lai!!!";
                break;
            case 1:
                createTree(ep);
                cout << "=========================================================\n";
                break;
            case 2:
                display(ep);
                cout << "=========================================================\n";
                break;
            case 3:
                findMax(ep);
                thongKeBonusMax(ep);
                cout << "=========================================================\n";
                break;
            case 4:
                Tree salaryTB;initTree(salaryTB);
                double tb = sum(ep)/Count(ep);
                // cout << tb << "\n";
                salaryLon(ep, salaryTB, tb);
                display(salaryTB);
                cout << "=========================================================\n";
                break;
            // default : 
            //     cout << "Vui long nhap lai\n";
            //     cout << "=========================================================\n";
        }
    } while(choice!=0);
    cout << "!!!\n";
    return 0;
}

