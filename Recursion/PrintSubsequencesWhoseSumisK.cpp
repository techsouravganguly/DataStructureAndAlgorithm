#include<bits/stdc++.h>
using namespace std;

/*
    Print all Subsequences whose sum is k
*/

void printSubsequencesWhoseSumIsK(vector<int>&, vector<int>&, int, int, int);
bool printAnySubsequencesWhoseSumIsK(vector<int>&, vector<int>&, int, int, int);
int coutSubsequencesWhoseSumIsK(vector<int>&, int, int, int);

int main() {
    vector<int> arr = {10, 8, 9, 2, 5, 8, 7, 12, 4};
    int n = arr.size();
    int sum = 15;
    vector<int> ds;
    printSubsequencesWhoseSumIsK(arr, ds, 0, sum, 0);
    ds.clear();
    printAnySubsequencesWhoseSumIsK(arr, ds, 0, sum, 0);
    cout << coutSubsequencesWhoseSumIsK(arr, 0, sum, 0);
}

void printVector(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] <<  " ";
    }
    cout << endl;
}

void printSubsequencesWhoseSumIsK(vector<int>& arr, vector<int>& ds, int cur, int sum, int curSum){
    if(cur == arr.size()){
        if(curSum == sum) printVector(ds);
        return;
    }
    curSum += arr[cur];
    ds.push_back(arr[cur]);
    printSubsequencesWhoseSumIsK(arr, ds, cur + 1, sum, curSum);
    
    curSum -= arr[cur];
    ds.pop_back();
    printSubsequencesWhoseSumIsK(arr, ds, cur + 1, sum, curSum);
    
}

bool printAnySubsequencesWhoseSumIsK(vector<int>& arr, vector<int>& ds, int cur, int sum, int curSum){
    if(cur == arr.size()){
        if(curSum == sum) {
            printVector(ds);
            return true;
        }
        return false;
    }

    curSum += arr[cur];
    ds.push_back(arr[cur]);
    if(printAnySubsequencesWhoseSumIsK(arr, ds, cur + 1, sum, curSum)) return true;

    curSum -= arr[cur];
    ds.pop_back();
    if(printAnySubsequencesWhoseSumIsK(arr, ds, cur  +1, sum, curSum)) return true;
    return false;

}

int coutSubsequencesWhoseSumIsK(vector<int>& arr, int cur, int sum, int curSum){
    if(cur == arr.size()) { 
        if(curSum == sum) return 1;
        return 0;
    }
    curSum += arr[cur];
    int pick = coutSubsequencesWhoseSumIsK(arr, cur + 1, sum, curSum);

    curSum -= arr[cur];
    int not_pick = coutSubsequencesWhoseSumIsK(arr, cur + 1, sum, curSum);
    return pick + not_pick;
}