#include <iostream>
using namespace std;

// them vao khi f=r=-1
void Enqueue1(int q[], int n, int f, int &r, int x){
    if(r == n-1){
        cout << "mang day";
        exit();
    }
    r++;
    q[r] = x;
}

// lay ra vao khi f=r=-1
int Dequeue1(int q[], int n, int &f, int r, int x){
    if(f == r){
        cout << "mang rong";
        exit();
    }
    f++;
    return q[f];
}

// them vao khi f=r=0
void Enqueue0(int q[], int n, int f, int &r, int x){
    if(r == n){
        cout << "mang day";
        exit();
    }
    q[r] = x;
    r++;
}

int main(){
    
}