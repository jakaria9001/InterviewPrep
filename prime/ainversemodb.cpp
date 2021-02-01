// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/maths-iii-introduction-to-modular-arithmetic-44c25510-08e2-444f-8010-4fec805b8934/#homework%2F9314
// To compute x^y under modulo m 
long power(long x, long y, long p) 
{ 
    long res = 1;     // Initialize result 
 
    x = x % p; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  

int Solution::solve(int A, int B) {
    
    // int ans = 1, n = B-2;
    // while(n>0){
    //     if(B&1) ans = (ans*A)%B;
    //     n>>=1;
    //     A = (A*A)%B;
    // }
    int ans = power(1ll*A,1ll*(B-2), 1ll*B);
    return ans;
}
