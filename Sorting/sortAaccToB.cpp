// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-iv/#homework

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

    map<int, int> mp;
    for(int x : A)
        mp[x]++;
    vector<int> ans;
    for(int y : B)
        if(mp.find(y)!=mp.end()){
            int k = mp[y];
            while(k--)
                ans.push_back(y);
            mp.erase(y);
        }
    // sort(mp.begin(),mp.end());
    
    for(pair<int,int> p : mp){
        int c = p.second;
        while(c--)
            ans.push_back(p.first);
    }
    return ans;
            
}
