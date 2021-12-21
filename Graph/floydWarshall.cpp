vector<vector<int> > Solution::solve(vector<vector<int> > &graph) {
    int nV = graph.size(); 
    vector<vector<int>> matrix(nV, vector<int>(nV, 1e7));
    int i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            if(graph[i][j]!=-1)
                matrix[i][j] = graph[i][j];

    // Adding vertices individually
    for (k = 0; k < nV; k++) {
        for (i = 0; i < nV; i++) {
            for (j = 0; j < nV; j++) {
                
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            if(matrix[i][j]==1e7)
                matrix[i][j]=-1;
    return matrix;
}
