#include<bits/stdc++.h>
using namespace std;


void quickSort(vector<int>&, int, int);
void printVector(vector<int>& arr) {
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 5, 9, 4, 1, 10, 2, 7, 3};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    printVector(arr);
}

int conqueror(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(i <= high &&  pivot >= arr[i]) i++;
        while(j >= low && pivot < arr[j]) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;

}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pivot = conqueror(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}