// Link: https://leetcode.com/problems/roman-to-integer/submissions/
class Solution {
public:
    int value(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int p=0, ans = 0;
        for(int i=s.length();i>=0;i--){
            if(value(s[i]) >= p)
                ans+=value(s[i]);
            else ans -= value(s[i]);
            p = value(s[i]);
        }
        return ans;
    }
};
