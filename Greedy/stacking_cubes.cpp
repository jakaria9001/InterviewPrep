// Stacking Cubes : 
/*
Problem Description - 

You are given A cubes that are of the same size. You are allowed to stack cubes on top of each other.

You should choose P cubes from the A cubes, such that you should stack all the remaining cubes on top of the P cubes, and each of the P cubes should have equal number of cubes on top of them.

Find and return the number of ways you can stack cubes on top of each other in the given manner.

NOTE: Every cube has to be stacked, you cannot have unstacked cubes. No stack can consist of a total of just one cube.
*/
int Solution::solve(int A) {
    int ans = 0;
    for(int x = 1;x*x<=A;x++)
        if(A%x==0)
            ans++;
    return ans;
}
