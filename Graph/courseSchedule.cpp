// link: https://leetcode.com/problems/course-schedule/submissions/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0)
                pq.push(i);
        }
        vector<int> ans;
        while(!pq.empty()){
            int t=pq.top();
            pq.pop();
            ans.push_back(t);
            for(auto v: adj[t]){
                in[v]--;
                if(in[v]==0) pq.push(v);
            }
        }
        return (ans.size()==numCourses);
    }
};
