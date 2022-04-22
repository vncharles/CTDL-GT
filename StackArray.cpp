#include <iostream>
using namespace std;

// push khi top = -1
void push1(int st[], int n, int &top, int x){
    if(top == n - 1){
        cout << "Mang day";
        exit();
    }
    top++;
    st[top] = x;
}

// push khi top = 0
void push2(int st[], int n, int &top, int x){
    if(top == n){
        cout << "Mang day";
        exit();
    }
    st[top] = x;
    top++;
}

// pop khi top = -1
int pop1(int st[], int n, int &top){
    if(top == -1){
        cout << "Mang rong";
        exit();
    }
    return st[top], top--;;  
}

// pop khi top = 0
int pop2(int st[], int n, int &top){
    if(top == 0){
        cout << "Mang rong";
        exit();
    }
    return st[top - 1], top--;  
}



int main(){

}