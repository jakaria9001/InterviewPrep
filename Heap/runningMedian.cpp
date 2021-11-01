// Link : https://leetcode.com/problems/find-median-from-data-stream/   

    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int>> l;
    
    
    void addNum(int n) {
        if(!s.size()||n<=s.top()) 
            s.push(n);
        else
            l.push(n);
        if(l.size()>s.size())
        {
            s.push(l.top());
            l.pop();
        }
        if(s.size()>l.size()+1)
        {
            l.push(s.top());
            s.pop();
        }
        
    }
    
    int findMedian() {
        if(s.size()==l.size())
            return s.top();
        return s.top();
    }

vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans;

s = priority_queue <int>(); // reset it

l = priority_queue <int,vector<int>,greater<int>>(); // reset it
    // priority_queue<int> maxHeap;
    // priority_queue<int,vector<int>, greater<int>> minHeap;
    
    // for(int x : A){
    //     // if x smaller than maxHeap's top, push it to maxHeap,else push to minHeap
    //     if(!maxHeap.size() || x<=maxHeap.top())
    //         maxHeap.push(x);
    //     else minHeap.push(x);
        
    //     // size differ by 2 : 
    //     if(maxHeap.size() - minHeap.size() > 1){
    //         // if()
    //         int temp = maxHeap.top();
    //         maxHeap.pop();
    //         minHeap.push(temp);
    //     }else if(maxHeap.size() - minHeap.size() < 0){
    //         int temp = minHeap.top();
    //         minHeap.pop();
    //         maxHeap.push(temp);
    //     }
    //     // if sizes of two heaps are equal (even no of elements)
    //     if(maxHeap.size() == minHeap.size())
    //         ans.push_back(min(maxHeap.top() , minHeap.top()));
    //     else 
    //         ans.push_back(maxHeap.top() );
    // }
    for(int x: A){
        addNum(x);
        ans.push_back(findMedian());
    }
    return ans;
}
