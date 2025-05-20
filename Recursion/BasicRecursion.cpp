#include<bits/stdc++.h>
using namespace std;
void printNameFiveTimes(string, int&);
void printLinearFromOneToN(int, int);
void printLinearFromNToOne(int);
void printLinearFromOneToNByBackTracking(int, int);

int main(){
    int nameCnt = 0;
    printNameFiveTimes("sourav", nameCnt);
    int n = 8;
    printLinearFromOneToN(1, n);
    printLinearFromNToOne(n);
    printLinearFromOneToNByBackTracking(n, n);
}


// print name 5 times
void printNameFiveTimes(string name, int& cnt){
    if(cnt == 5) return;
    cout << name << endl;
    cnt++;
    printNameFiveTimes(name, cnt);
}

// print Linear from 1-> n
void printLinearFromOneToN(int itr, int n){
    if(itr > n) return;
    cout << itr << endl;
    printLinearFromOneToN(++itr, n);
}

// print Linear from n -> 1
void printLinearFromNToOne(int n){
    if(n == 0) return;
    cout << n << endl;
    printLinearFromNToOne(--n);
}

void printLinearFromOneToNByBackTracking(int itr, int n){
    if(itr < 1) return;
    printLinearFromOneToNByBackTracking(itr - 1, n);
    cout << itr << endl;
}
