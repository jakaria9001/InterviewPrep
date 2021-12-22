// Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    void recur(vector<string> &ans, string digits, string cur, int idx, vector<string> &mappings){
        if(idx == digits.length()){
            ans.push_back(cur);
            return;
        } 
        
        string letters = mappings[digits[idx]-'0'];
        for(char ch: letters){
            recur(ans, digits, cur+ch, idx+1,mappings);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        
        vector<string> mappings = {
            "0",
            "1", "abc", "def", "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        
        recur(ans, digits, "", 0, mappings);
        return ans;
    }
};
