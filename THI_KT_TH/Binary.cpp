-#include <iostream>
using namespace std;

// =====================================
// Các hàm khởi tạo cây
struct TNode {
    int data;
    TNode *left;
    TNode *right;
};

TNode *getTNode(int init) {
    TNode *p = new TNode;
    p->data = init;
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
void addTNode(Tree &T, int x) {
    if(T) {
        if (T->data == x) return;
        if (x < T->data) addTNode(T->left, x);
        else addTNode(T->right, x);
    } else T = getTNode(x);
}

void createTree(Tree &T){
    int x;
    while(true){
        cout << "Nhap x(-1 de exit): "; cin >> x;
        if(x == -1) break;
        addTNode(T, x);
    }
}

// =========================================
// Các hàm xử lí xuất cây
void NLR(Tree T) {
    if(T) {
        cout << T->data << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

void LRN(Tree T) {
    if(T) {
        LRN(T->left);
        LRN(T->right);
        cout << T->data << " ";
    }
}

void LNR(Tree T) {
    if(T) {
        LNR(T->left);
        cout << T->data << " ";
        LNR(T->right);
    }
}

// Các hàm sử lí cây
//tim kiem
int findX(Tree T, int x){
    if (T) {
        if (T->data == x)
            return 1;
        if (x < T->data)
            return findX(T->left, x);
        return findX(T->right, x);
    }
    return 0;
}

// dem so node
int Count(Tree T) {
    if(T == NULL) return 0;
    return 1 + Count(T->left) + Count(T->right);
}

// dem so node co gtri chan
int countEven(Tree T) {
    if(T == NULL) return 0;
    if(T->data%2 == 0) 
        return 1 + countEven(T->left) + countEven(T->right);
    return countEven(T->left) + countEven(T->right);
}

// dem la
int countLeaf(Tree T){
    if(T == NULL) return 0;
    if(T->left == NULL && T->right == NULL)
        return 1;
    return countLeaf(T->left) + countLeaf(T->right);
}

// dem node co 1 con
int countOneChild(Tree T) {
    if(T == NULL) return 0;
    if((T->left != NULL && T->right == NULL) || (T->left == NULL && T->right != NULL))
        return countOneChild(T->left) + countOneChild(T->right) + 1;
    return countOneChild(T->left) + countOneChild(T->right);
}

// dem node co 2 con
int countTwoChild(Tree T){
    if(T == NULL) return 0;
    if(T->left != NULL && T->right != NULL)
        return countTwoChild(T->left) + countTwoChild(T->right) + 1;
    return countTwoChild(T->left) + countTwoChild(T->right);
}

int dem1COn(Tree T)
{
    if(T==NULL)
        return 0;
    if((T->left==NULL && T->right!=NULL) || (T->left!=NULL && T->right==NULL))
        return dem1COn(T->left)+ dem1COn(T->right)+1;
    return dem1COn(T->left)+dem1COn(T->right);
}

// tong cac phan tu cua cay
int sum(Tree T) {
    if(T == NULL) return 0;
    return T->data + sum(T->left) + sum(T->right);
}

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

// Huy mot phan tu
void delNode(Tree &root, int x){
    if(root == NULL) return;
    if(root->data > x) return delNode(root->left, x);
    if(root->data < x) return delNode(root->right, x);

    TNode* p = root;
    if(root->left == NULL)
        root = root->right;
    else if(root->right == NULL)
        root = root->left;
    else searchStandFor(p, root->right);
    delete p;
}

// =========================================
// Main
int main(){
    Tree T;
    initTree(T);

    createTree(T);

    int xoa; cin >> xoa;
    delNode(T, xoa);

    cout << "LNR = ";
    LNR(T);
    
    // cout << "\n" << findX(T, 3);
    // cout << "\nSo luong node: " << Count(T);
    // cout << "\nSo luong node chan: " << countEven(T);
    // cout << "\nSo la: " << countLeaf(T);
    // cout << "\nSo luong node 1 con: " << dem1COn(T);
    // cout << "\nSo luong node 2 con: " << countTwoChild(T);
    // cout << "\nTong cua tree la: " << sum(T);

    
    
    
}