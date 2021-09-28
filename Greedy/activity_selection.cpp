// Link: https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

int Solution::solve(vector<int> &s, vector<int> &f) {
    // int n = A.size();
    // vector<pair<int, int>> activity(n);
    
    // for(int i=0;i<n;i++){
    //     activity[i] = {A[i],B[i]};
    // }
    
    // sort(activity.begin() , activity.end());
    
    // int ans = 0, i =0;
    
    // for(int j=1;j<n;j++){
    //     if(activity[j].first >= activity[i].second ){
    //         ans++;
    //         i = j;
    //     }
    // }
    
    // return ans;

    vector<pair<int,int>>ans;
 
    // Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]).
 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
 
    for(int i=0;i<s.size();i++){
        // Pushing elements in priority queue where the key is f[i]
        p.push(make_pair(f[i],s[i]));
    }
 
    auto it = p.top();
    int start = it.second;
    int end = it.first;
    p.pop();
    ans.push_back(make_pair(start,end));
 
    while(!p.empty()){
        auto itr = p.top();
        p.pop();
        if(itr.second >= end){
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start,end));
        }
    }
    return ans.size();
}
