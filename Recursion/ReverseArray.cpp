#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>&, int, int);

/*
    Question: Reverse an array
*/

void printArray(vector<int>& arr) {
    for(auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {9, 10, 89, 7, 36, 90};
    int left = 0;
    int right = arr.size() - 1;
    printArray(arr);
    reverseArray(arr, left, right);
    printArray(arr);

}

// Reverse the given arry on the basis of left and right
void reverseArray(vector<int>& arr, int left, int right) {
    if(left >= right) return;
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
    reverseArray(arr, left + 1, right - 1);
}