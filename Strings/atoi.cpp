// Link  : https://www.scaler.com/academy/mentee-dashboard/classroom/strings-28a5414c-fb19-4ef6-a8e8-983a46f077e1/#homework

int Solution::atoi(const string A) {
    int ans = 0;
    int i=0, n = A.length(), sign = 1;
    // ignore all previous spaces : 
    while(i<n && A[i]==' ') i++;
    // get the sign, if any : 
    if(A[i]=='-' || A[i]=='+') sign = 1-2*(A[i++]=='-');
    
    // add all the corresponding digits to the answer and also check for the overflow : 
    while(i<n && isdigit(A[i])){
        
        if(ans >= INT_MAX/10) 
            if(sign==1) return INT_MAX;
            else return INT_MIN;
            
        ans = ans*10 + (A[i++]-'0');
        
    }
    
    return ans*sign;
}
