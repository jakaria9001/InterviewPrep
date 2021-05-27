// Link : https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> ans;
    
    void printAll(int ind, char temp[], int n,int open,int close){
        // base case:
        if(ind==2*n){
            string tmp = "";
            for(int i=0;i<2*n;i++)
                tmp+=temp[i];
            ans.push_back(tmp);
            return;
        }
        // open > close:
        if(open>close){
            temp[ind] = ')';
            printAll(ind+1, temp, n, open, close+1);
        }
        //open < n :
        if(open<n){
            temp[ind] = '(';
            printAll(ind+1, temp, n, open+1, close);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        char temp[2*n];
        int ind = 0, open = 0, close = 0;
        
        printAll(ind, temp, n, open, close);
        
        return ans;
        
    }
};
