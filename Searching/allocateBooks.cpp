bool isPoss(vector<int> &arr, int n, int m, int curr_min){
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr_min)
            return false;
            
        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;
 
            curr_sum = arr[i];
 
            if (studentsRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}

int books(vector<int> &A, int B) {
    int n = A.size();

    if(n<B) return -1;

    long long int sum = 0;
    for(int x: A) sum +=x;

    int start = 0, end = sum;
    int ans = INT_MAX;

    while(start<=end){
        int mid = (start + end) / 2;
        if (isPoss(A, n, B, mid))
        {
            
              ans = mid;
 
            end = mid - 1;
        }
 
        else
            start = mid + 1;
    }
    return ans;
}
int main()
{
    //Number of pages in books
    int n ; cin>>n;
    vector<int> arr(n);
    
    int m; cin>>m;
 
    cout << "Minimum number of pages = "<< findPages(arr, n, m) << endl;
    return 0;
}
