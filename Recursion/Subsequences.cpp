#include<bits/stdc++.h>
using namespace std;

void subsequence(vector<int>&, int, vector<int>&);
/*
    Question 1:  Print all subsequence.
*/

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ds;
    subsequence(arr, 0, ds);

}

// Print all subsequence of an array.
void subsequence(vector<int> &arr, int itr, vector<int>& ds) {
    if(itr >= arr.size()){
        for(auto it : ds){
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[itr]);
    subsequence(arr, itr + 1, ds);
    ds.pop_back();
    subsequence(arr, itr + 1, ds);
}
