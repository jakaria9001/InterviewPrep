// Link : https://www.hackerrank.com/contests/cse-2430-spring-2020-final-exam/challenges/game-of-prime

#include <bits/stdc++.h>
using namespace std;


int main() {
    // sieve : 
    int n = 541;
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    int xyz[100], idx=0;
    for(int i=1;i<n;i++)
        if(prime[i])
            xyz[idx++] = i;
    
    // for(int i=0;i<100;i++) cout<<xyz[i]<<" ";
    
    int t; cin>>t;
    
    for(int x=1;x<=t;x++)
    {
        int N, M;
        cin>>N>>M;
        int ans = 0;
        
        for(int i= N-1;i>=0;i--){
            if(M % xyz[i] == 0){
                ans = M/xyz[i];
                break;
            }
        }
        
        cout<<"Case "<<x <<": "<<ans <<endl;
    }
    return 0;
}
