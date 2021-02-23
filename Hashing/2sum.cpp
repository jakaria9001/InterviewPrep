// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/intro-to-hashing/#assignment
vector<int> Solution::twoSum(const vector<int> &arr, int B) {
    map<int, int> myy;
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        if(myy.find(B-arr[i])!=myy.end()){
            
            ans.push_back(myy[B-arr[i]]+1);
            ans.push_back(i+1);
            return ans;
        }else if(myy.find(arr[i])==myy.end()) myy[arr[i]] = i;
    }
    return ans;
}
