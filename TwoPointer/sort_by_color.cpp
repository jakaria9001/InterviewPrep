// link: https://algodaily.com/challenges/dutch-national-flag-problem

vector<int> Solution::sortColors(vector<int> &A) {
    int n = A.size();

    int st = 0, mid = 0, en = n-1;

    while(mid<en){
        if(A[mid]==0){
            swap(A[st],A[mid]);
            st++;
        }else if(A[mid]==2){
            swap(A[en],A[mid]);
            en--;mid--;
        }
        mid++;
    }

    return A;
}
