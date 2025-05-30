#include<bits/stdc++.h>
using namespace std;

int fibonacci(int);

int main() {
    int n = 9;
    cout << fibonacci(n) <<  endl;
}

int fibonacci(int n) {
    if(n == 0 || n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
    
}