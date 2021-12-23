// Link: https://leetcode.com/problems/combination-sum/
void recur(vector<int> &combns, int target, set<vector<int>> &res, vector<int> &temp, int indx){
    if(target < 0) return;

    if(target==0){
        res.insert(temp);
        return;
    }

    for(int i=indx;i<combns.size();i++){
        int x = combns[i];
        if(x > target) break;
        temp.push_back(x);
        recur(combns, target-x, res, temp, i);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());

    set<vector<int>> res;
    vector<int> temp;
    recur(A, B, res, temp, 0);
    vector<vector<int>> rest(res.begin(),res.end());
    return rest;
}
