// MInimum Largest element after B oprtstions:
// In each operation, pick any element and replace it with its original value;

struct Node{
    int cvalue;
    int ovalue;
};
bool operator<(Node a, Node b){
    return ((a.cvalue+a.ovalue)>=(b.cvalue+b.ovalue));
}
typedef pair<int, int> pi;
int Solution::solve(vector<int> &A, int B) {
    // priority_queue<pi,vector<pi>,greater<pi> > pq;
    // priority_queue<Node, vector<Node>, greater<Node>> pq;
    priority_queue<Node> pq;
    for(int x: A)
        pq.push({x,x});
    
    while(B--){
        // pi t = pq.top();
        Node t = pq.top();
        pq.pop();
        pq.push({t.cvalue+t.ovalue, t.ovalue});
        // pq.push({t.first+t.second, t.second});
    }
    int mx = INT_MIN;
    while(pq.size()){
        mx = max(mx, pq.top().cvalue);   
        pq.pop();
    }
    // return pq.top().cvalue;
    return mx;
    
}
