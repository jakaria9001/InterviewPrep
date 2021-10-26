// Link : https://www.geeksforgeeks.org/count-minimum-right-flips-to-set-all-values-in-an-array/

int Solution::bulbs(vector<int> &A) {
    int n = A.size();

    int ans = 0;

    int flag = 0;

    for(int i=0;i<n;i++){
        if(A[i] && flag%2 == 0) continue;
        else if(!A[i] && flag%2 != 0) continue;
        else if(A[i] && flag%2!=0){
            ans++;
            flag++;
        }
        else if(!A[i] && flag%2==0){
            ans++;
            flag++;
        }

    }
    return ans; 
}
