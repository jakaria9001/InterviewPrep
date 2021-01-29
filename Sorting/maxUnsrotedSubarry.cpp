// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-ii-673c2b42-c142-44de-b86a-2fd44f63429f/?status=active#assignment

vector<int> Solution::subUnsort(vector<int> &A) {
    
    vector<int> temp = A;
    
    sort(temp.begin(),temp.end());
    int st = 0, en = A.size()-1;
    while(st<=en && A[st]==temp[st])
        st++;
    while(en>=0 && A[en]==temp[en])
        en--;
    if(st>=en) return {-1};
    vector<int> ans;
    // for(int i=st;i<=en;i++)
    ans.push_back(st);
    ans.push_back(en);
    return ans;
    
}
