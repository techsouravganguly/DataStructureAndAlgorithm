#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/combination-sum/ -> combination- I
// https://leetcode.com/problems/combination-sum-ii/ -> combination -II



void recur(vector<int>& candidates,vector<int>& ds, int target, int curSum, int cur, vector<vector<int>>& ans) {
    if(curSum > target) return;
    if(cur == candidates.size()){
        if(target == curSum) {
            ans.push_back(ds);
        }
        return;
    }
    curSum += candidates[cur];
    ds.push_back(candidates[cur]);
    recur(candidates, ds, target, curSum, cur, ans);
    curSum -= candidates[cur];
    ds.pop_back();
    recur(candidates, ds, target, curSum, cur + 1, ans);
}

vector<vector<int>> combinationSumI(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    recur(candidates, ds, target, 0, 0, ans);
    return ans;
}

void recur2(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds, int cur){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i = cur; i < candidates.size(); i++){
        if(i > cur && candidates[i] == candidates[i - 1]) continue;
        if(candidates[i] > target) break;
        ds.push_back(candidates[i]);
        recur2(candidates, target - candidates[i], ans, ds, i + 1);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    recur2(candidates, target, ans, ds, 0);
    return ans;
    
}


void printVector(vector<int>& arr) {
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}

int main() {

    vector<int> candidates = {2, 3, 6, 7};
    int n = candidates.size();
    int target = 7;
    cout << "combinationSumI" << endl;
    vector<vector<int>> ans = combinationSumI(candidates, target);
    for(auto it: ans){
        printVector(it);
    }
    cout << "combinationSum2" << endl;
    vector<vector<int>> ans1 = combinationSum2(candidates, target);
    for(auto it: ans1){
        printVector(it);
    }
}

