/*

Given an integer n, you have to find the Ath Perfect Number.

A Perfect Number has the following properties:

It comprises only 1 and 2.

The number of digits in a Perfect number is even.

It is a palindrome number.

For example 11, 22, 112211 are Perfect numbers, where 123, 121, 782, 1 are not.
*/

// Solution: 
string Solution::solve(int n) {
    queue<string> q;
    q.push("1");
    q.push("2");
    
    int i=0;
    string xx = "";
    
    while(i<n){
        xx = q.front();
        q.pop();
        q.push(xx+"1");
        q.push(xx+"2");
        i++;
    }
    string ans=xx;
    reverse(xx.begin(),xx.end());
    ans+=xx;
    
    return ans;
}
