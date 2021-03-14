// Link : https://leetcode.com/problems/min-stack/submissions/

class MinStack {
    stack<int> origSt, minSt;
public:
    /** initialize your data structure here. */
    MinStack() {
        // this->origSt = origSt;
        // this->minSt = minSt;
    }
    
    void push(int x) {
        if(origSt.empty()){
            origSt.push(x);
            minSt.push(x);
        }else{
            origSt.push(x);
            if(x <= minSt.top())
                minSt.push(x);
        }        
    }
    
    void pop() {
        if(origSt.empty())
            return;
        if(origSt.top()==minSt.top()){
            origSt.pop();
            minSt.pop();
        }else origSt.pop();        
    }
    
    int top() {
        if(origSt.empty())
            return 0;
        else return origSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
