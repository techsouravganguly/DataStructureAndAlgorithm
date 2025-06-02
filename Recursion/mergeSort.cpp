#include<bits/stdc++.h>
using namespace std;



void mergeSort(vector<int>&, int, int);
void printVector(vector<int>& arr) {
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {9, 10, 7, 8, 6, 2, 31};
    int low = 0, high = arr.size() - 1;
    mergeSort(arr, low, high);
    printVector(arr);
}

void merge(vector<int>& arr, int low, int mid, int high) {
    int left = low, right = mid + 1;
    vector<int> tmp;
    while(left <= mid && right <= high) {
        if(arr[left] < arr[right]){
            tmp.push_back(arr[left]);
            left++;
        } 
        else  {
            tmp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        tmp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        tmp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++) { 
        arr[i] = tmp[i - low];
    }
    
}

void mergeSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}