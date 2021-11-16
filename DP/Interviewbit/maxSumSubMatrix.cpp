// Link: https://www.tutorialspoint.com/Maximum-sum-rectangle-in-a-2D-matrix
int kadaneAlgo(int arr[], int &start, int &end, int n) {    //find max sum and starting and ending location
   int sum = 0, maxSum = INT_MIN;

   end = -1;    //at first no place is selected

   int tempStart = 0;    //starting from 0

   for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (sum < 0) {
         sum = 0;
         tempStart = i+1;
      }else if (sum > maxSum) {     //get maximum sum, and update start and end index
         maxSum = sum;
         start = tempStart;
         end = i;
      }
   }

   if (end != -1)
      return maxSum;
   //when all elements are negative in the array
   maxSum = arr[0];
   start = end = 0;

   // Find the maximum element in array
   for (int i = 1; i < n; i++) {
      if (arr[i] > maxSum) {
         maxSum = arr[i];
         start = end = i;
      }
   }
   return maxSum;
}

int maxSumRect(vector<vector<int>> &M) {
   int maxSum = INT_MIN, endLeft, endRight, endTop, endBottom;
   int ROW = M.size(), COL = M[0].size();

   int left, right;
   int temp[ROW], sum, start, end;

   for (left = 0; left < COL; left++) {
      for(int i = 0; i<ROW; i++)//temp initially holds all 0
         temp[i] = 0;

      for (right = left; right < COL; ++right) {
         for (int i = 0; i < ROW; ++i)    //for each row, find the sum
            temp[i] += M[i][right];
         sum = kadaneAlgo(temp, start, end, ROW);    //find sum of rectangle (top, left) and (bottom right)

         if (sum > maxSum) {    //find maximum value of sum, then update corner points
            maxSum = sum;
            endLeft = left;
            endRight = right;
            endTop = start;
            endBottom = end;
         }
      }
   }

//    cout << "(Top, Left) ("<<endTop<<", "<<endLeft<<")"<<endl;
//    cout << "(Bottom, Right) ("<<endBottom<<", "<<endRight<<")"<<endl;
//    cout << "The max sum is: "<< maxSum;
   return maxSum;
}

int Solution::solve(vector<vector<int> > &A) {
    
    return max(0, maxSumRect(A));

}
