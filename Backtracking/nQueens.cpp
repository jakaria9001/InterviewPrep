// Link:  https://leetcode.com/problems/n-queens/

// vector<vector<string>> ans;

// void nQueens(int row, int N, vector<vector<int>>& board){
//     if(row==N){
//         // store board in ans
//         vector<string> temp;
//         for(int i=0;i<N;i++){
//             string trow="";
//             for(int j=0;j<N;j++){
//                 if(board[i][j]==0) trow+='.';
//                 else trow+='Q';
//             }
//             temp.push_back(trow);
//         }
//         ans.push_back(temp);
//         return;
//     }
//     unordered_set<int> row_set, col_set, left_diag_set, right_diag_set;
    
//     for(int col=0;col<N;col++){
//         if(row_set.find(row) == row_set.end() &&
//             col_set.find(col) == col_set.end() &&
//             left_diag_set.find(row+col) == left_diag_set.end() && 
//             right_diag_set.find(row-col) == right_diag_set.end()){
//                 //setting the row,col th value of board as 1
//                 board[row][col] = 1;
                
//                 row_set.insert(row);
//                 col_set.insert(col);
//                 left_diag_set.insert(row+col);
//                 right_diag_set.insert(row-col);
                
//                 nQueens(row+1, N, board);
                
//                 board[row][col] = 0;
//                 row_set.erase(row);
//                 col_set.erase(col);
//                 left_diag_set.erase(row+col);
//                 right_diag_set.erase(row-col);
                
//             }
//     }
// }

// vector<std::vector<std::string> > solveNQueens(int n) {
//         std::vector<std::vector<std::string> > res;
//         std::vector<std::string> nQueens(n, std::string(n, '.'));
//         solveNQueens(res, nQueens, 0, n);
//         return res;
//     }
    
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }

    void solveQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // ans.clear();
    
    // // int board[A][A];
    // vector<vector<int>> board(A, vector<int>(A));
    // nQueens(0,A,board);
    
    // return ans;
    
    vector<vector<string> > res;
        vector<string> nQueens(A, string(A, '.'));
        solveQueens(res, nQueens, 0, A);
        return res;
}
