// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/maths-iii-introduction-to-modular-arithmetic-44c25510-08e2-444f-8010-4fec805b8934/#homework

long square(long n) { return n * n; } 

// Recursive function to return sum of greatest 
// odd divisor of numbers in range [1, n] 
long sum(long n) 
{ 
	if (n == 0) 
		return 0; 
	if (n % 2 == 1) { // Odd n 
		return square((n + 1) / 2) + sum(n / 2);	 
	} 
	else { // Even n 
		return square(n / 2) + sum(n / 2); 
	} 
} 

// Function to return sum of greatest 
// odd divisor of numbers in range [a, b] 
long oddDivSum(int a, int b) 
{ 
	return sum(b) - sum(a - 1); 
}
int Solution::solve(int A, int B) {
    int mod = pow(10,9)+7;
    long ans = (oddDivSum(A,B))%mod;
    return ans;
}
