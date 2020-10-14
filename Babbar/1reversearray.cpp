
// Link : https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
// iterative:
void reverse(int a[],int start, int end){
  
    while(start<end){
      int temp = a[start];
      a[start]=a[end];
      a[end] = temp;
    }
}

// Recursive : 

void reverse(int a[],int start, int end){
  
    //base case:
    if(start>= end)
      return;
    
      int temp = a[start];
      a[start]=a[end];
      a[end] = temp;
    
    return reverse(a,start+1,end-1);
    
}
