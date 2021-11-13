// Link: interviewbit.com/problems/seats/

//Solution: 
int Solution::seats(string A) {
    vector<int>pos;

    for(int i=0;i<A.size();i++){

        if(A[i]=='x')

         pos.push_back(i);

    }

    int n=pos.size();

    long long int ans=0;

    int mid=n/2;int k=1;

    for(int i=mid-1;i>=0;i--){

        ans=(ans+pos[mid]-k-pos[i])%10000003;

        k++;

    }

    k=1;

    for(int i=mid+1;i<n;i++){
// 16
        ans=(ans+pos[i]-(pos[mid]+k))%10000003;
// 17
        k++;
// 18
    }
// 19
    return ans%10000003;
}
