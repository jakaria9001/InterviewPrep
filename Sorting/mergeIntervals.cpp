// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-iv/#assignment
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 
  
// The main function that takes a set of intervals, merges 
// overlapping intervals and prints the result 
vector<Interval> mergeIntervals(Interval arr[], int n) 
{ 
    vector<Interval> ans;
    // Test if the given set has at least one interval 
    if (n <= 0) 
        return ans; 
  
    // Create an empty stack of intervals 
    stack<Interval> s; 
  
    // sort the intervals in increasing order of start time 
    sort(arr, arr+n, compareInterval); 
  
    // push the first interval to stack 
    s.push(arr[0]); 
  
    // Start from the next interval and merge if necessary 
    for (int i = 1 ; i < n; i++) 
    { 
        // get interval from stack top 
        Interval top = s.top(); 
  
        // if current interval is not overlapping with stack top, 
        // push it to the stack 
        if (top.end < arr[i].start) 
            s.push(arr[i]); 
  
        // Otherwise update the ending time of top if ending of current 
        // interval is more 
        else if (top.end < arr[i].end) 
        { 
            top.end = arr[i].end; 
            s.pop(); 
            s.push(top); 
        } 
    } 
  
    // Print contents of stack 
    // cout << "\n The Merged Intervals are: "; 
    while (!s.empty()) 
    { 
        Interval t = s.top(); 
        ans.push_back({t.start , t.end}); 
        s.pop(); 
    } 
    sort(ans.begin(),ans.end(),compareInterval);
    return ans; 
} 


// bool compareT(Interval a, Interval b){
//     return a.end < b.end;
// }
vector<Interval> Solution::merge(vector<Interval> &arr) {
    int n = arr.size();
    Interval brr[n];
    for(int i=0;i<n;i++)
        brr[i] = arr[i];

    vector<Interval> ans = mergeIntervals(brr, n); 
    // for (int i = 0; i <= index; i++)  
    //     ans.push_back(arr[i]);
    
    // vector<Interval> ans1 = ;
    return ans;
    // // { (1,3) , (2,6) , (8,10) , (15,18) }   => { (1,6) , (8,10) , (15,18) } 
    // // if(A.size()==1) return A;
    // sort(arr.begin(), arr.end(), compareT);
    // int n = arr.size();
    
    // // int index = 0;
    
    // // for(int i=1;i<n;i++){
    // //     if(A[index].end>=A[i].start){
    // //         A[index].start = min(A[index].start, A[i].start);
            
    // //         A[index].end = max(A[index].end, A[i].end);
    // //     }else {
    // //         index++;
    // //         A[index] = A[i];
    // //     }
    // // }
    
    
    // int index = 0; // Stores index of last element  
    // // in output array (modified arr[])  
  
    // // Traverse all input Intervals  
    // for (int i=1; i<n; i++)  
    // {  
    //     // If this is not first Interval and overlaps  
    //     // with the previous one  
    //     if (arr[index].end >=  arr[i].start)  
    //     {  
    //           // Merge previous and current Intervals  
    //         arr[index].end = max(arr[index].end, arr[i].end);  
    //         arr[index].start = min(arr[index].start, arr[i].start);  
    //     }  
    //     else { 
    //         index++; 
    //         arr[index] = arr[i];  
    //     }     
    // }  
    
    
    
}
