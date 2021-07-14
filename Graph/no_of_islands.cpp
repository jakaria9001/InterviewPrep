const int rows[] = {-1,-1,-1,0,0,1,1,1};
const int cols[] = {-1,0,1,-1,1,-1,0,1};
int n,m;

bool isValid(int x, int y){
    return (x>=0 && y>=0 && x<n && y<m);
}
void dfs(int i, int j,vector<vector<bool> > &visited,vector<vector<int> > &mat ){
    visited[i][j] = true;
    for(int k=0;k<8;k++){
        int x = i+rows[k];
        int y = j+cols[k];
        if(isValid(x,y) && mat[x][y]==1){
            if(!visited[x][y]) dfs(x,y,visited, mat);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    
    n = A.size(), m = A[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && A[i][j]==1){
                dfs(i,j,visited, A);
                count++;
            }
        }
    }
    return count;
}
