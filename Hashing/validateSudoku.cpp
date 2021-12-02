// Link : https://leetcode.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &board) {
    

    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            unordered_set<char> s;
            for(int k = i; k < i+3; k++)
            {
                for(int l=j; l < j+3; l++)
                {
                    if(board[k][l]!='.')
                    {
                        if(s.find(board[k][l]) != s.end()){
                            return false;
                        }
                        else s.insert(board[k][l]);
                    }
                }

                    
            }
        }
    }
      for(int i = 0; i<9; i++)
    {
        unordered_set<char> s1;
        unordered_set<char> s2;
        for(int j=0; j<9; j++)
        {
            
            if(board[i][j]!='.')
                {
                    if(s1.find(board[i][j]) != s1.end()){
                        return false;
                    }
                    else s1.insert(board[i][j]);
                }
            
            
            if(board[j][i]!='.')
                {
                    if(s2.find(board[j][i]) != s2.end()){
                        return false;
                    }
                    else s2.insert(board[j][i]);
                }
            
            
            }

        }
    
    
    return true;
}
