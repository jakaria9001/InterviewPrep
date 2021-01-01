// Link: https://www.scaler.com/academy/mentee-dashboard/classroom/bit-manipulation-i-01b77058-12ae-4b20-a851-1667b9f72a0d/#assignment
unsigned int Solution::reverse(unsigned int num) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unsigned int count = sizeof(num) * 32 - 1; 
    unsigned int reverse_num = num; 
      
    num >>= 1;  
    while(num) 
    { 
       reverse_num <<= 1;        
       reverse_num |= num & 1; 
       num >>= 1; 
       count--; 
    } 
    reverse_num <<= count; 
    return reverse_num;
}
