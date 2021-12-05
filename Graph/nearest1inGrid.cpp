// Link: https://www.tutorialcup.com/interview/queue/distance-of-nearest-cell-having-1-in-a-binary-matrix.htm

// class representing coordinates of a cell in matrix
class Coordinate {
    public:
    int row;
    int col;
    
    Coordinate(int r, int c) {
        row = r;
        col = c;
    }
};

vector<vector<int> > Solution::solve(vector<vector<int> > &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> ans(n, vector<int>(m));
    
    // create a queue of coordinates
    // push all the elements that are equals to 1 in the matrix array to the queue
    queue<Coordinate> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                Coordinate coordinate(i, j);
                q.push(coordinate);
            }
        }
    }
    
    // initialize minDistance as 0
    int minDistance = 0;
    
    while (!q.empty()) {
        // initialize size as size of queue
        int size = q.size();
        
        // Run a loop size times
        for (int i = 0; i < size; i++) {
            // remove an element from queue
            Coordinate curr = q.front();
            q.pop();
            
            // ans to this coordinate is minDistance
            ans[curr.row][curr.col] = minDistance;
            
            // enqueue all the valid adjacent cells of curr that are equals to
            // 0 in the matrix array and set them as 1
            
            // left adjacent
            int leftRow = curr.row - 1;
            int leftCol = curr.col;
            if ((leftRow >= 0 && leftRow < n) && (leftCol >= 0 && leftCol < m)) {
                if (matrix[leftRow][leftCol] == 0) {
                    Coordinate cLeft(leftRow, leftCol);
                    q.push(cLeft);
                    matrix[leftRow][leftCol] = 1;
                }
            }
            
            // right adjacent
            int rightRow = curr.row + 1;
            int rightCol = curr.col;
            if ((rightRow >= 0 && rightRow < n) && (rightCol >= 0 && rightCol < m)) {
                if (matrix[rightRow][rightCol] == 0) {
                    Coordinate cRight(rightRow, rightCol);
                    q.push(cRight);
                    matrix[rightRow][rightCol] = 1;
                }
            }
            
            // up adjacent
            int upRow = curr.row;
            int upCol = curr.col + 1;
            if ((upRow >= 0 && upRow < n) && (upCol >= 0 && upCol < m)) {
                if (matrix[upRow][upCol] == 0) {
                    Coordinate cUp(upRow, upCol);
                    q.push(cUp);
                    matrix[upRow][upCol] = 1;
                }
            }
            
            // down adjacent
            int downRow = curr.row;
            int downCol = curr.col - 1;
            if ((downRow >= 0 && downRow < n) && (downCol >= 0 && downCol < m)) {
                if (matrix[downRow][downCol] == 0) {
                    Coordinate cDown(downRow, downCol);
                    q.push(cDown);
                    matrix[downRow][downCol] = 1;
                }
            }
        }
        
        // increment minimum distance
        minDistance++;
    }
    
    return ans;
}
