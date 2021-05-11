class Solution{   
public:
    long long maxProduct(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        long long mx1=arr[n-1], mx2 = arr[n-2], mx3 = arr[n-3];
        long long mn1 = arr[0], mn2 = arr[1];
        
        return max(mx1*mx2*mx3, mx1*mn1*mn2);
    }
    // int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;
 
    // // Initialize Minimum and second mimimum element
    // int minA = INT_MAX, minB = INT_MAX;
 
    // for (int i = 0; i < n; i++)
    // {
    //     // Update Maximum, second maximum and third
    //     // maximum element
    //     if (arr[i] > maxA)
    //     {
    //         maxC = maxB;
    //         maxB = maxA;
    //         maxA = arr[i];
    //     }
 
    //     // Update second maximum and third maximum element
    //     else if (arr[i] > maxB)
    //     {
    //         maxC = maxB;
    //         maxB = arr[i];
    //     }
 
    //     // Update third maximum element
    //     else if (arr[i] > maxC)
    //         maxC = arr[i];
 
    //     // Update Minimum and second mimimum element
    //     if (arr[i] < minA)
    //     {
    //         minB = minA;
    //         minA = arr[i];
    //     }
 
    //     // Update second mimimum element
    //     else if(arr[i] < minB)
    //         minB = arr[i];
    // }
 
    // return max(minA * minB * maxA,
    //           maxA * maxB * maxC);
};
