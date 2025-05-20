// This will Explain about two types of Recursion Parameterised and Fuctional.
#include<bits/stdc++.h>
using namespace std;


void parameterisedSum(int, int&);
int functionalSum(int);
int factorial(int);

/*
    Question 1: sum of number 1 -> n
    Question 2: Factorial of number n
*/


int main() {
    int sum = 0;
    int n = 8;
    parameterisedSum(8, sum);
    cout << "Parameterised Sum" << endl;
    cout << sum << endl;
    cout << "Functional sum" << endl;
    cout << functionalSum(n) << endl;
    cout << "Factorial of the number n:" << endl;
    cout << factorial(n) << endl;
}

// function recursion to calculate factorial of a number
int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

// parameterised recursion for finding sum
void parameterisedSum(int itr, int& sum) {
    if(itr == 0) return;
    sum += itr;
    parameterisedSum(itr - 1, sum);
}

// functional recursion for finding sum
int functionalSum(int n) {
    if(n == 0) return 0;
    return n + functionalSum(n - 1);
}


