/*
Higher rating higher holidays.
Scooby's summer vacations are about to start. Scooby and all his school friends are sitting in the class in a single line.
Every one in the class has a rating depending on their performance in InterviewBit contests. Number of holidays a child will get is dependent on the child's relative performance.

The teacher is kind and wants to give atleast one holiday to each child. If two children are sitting next to each other then the child with higher rating should always get more holidays. The teacher however wants to minimize the sum of holidays give to each child. Help the teacher in distributing holidays to children.

Constraints:

Number of children in class 1<='N'<=100000
Rating of each child 1<=R<=100000
Input: Each test case contains an integer array . This array gives the rating of the ith child.

Output: Return a single integer corresponding to the minimum sum of holidays given to children.

Example:

Input:

3 1 2 2 
Output:

4
*/

// Link: https://www.interviewbit.com/problems/distribute-candy/

int Solution::solve(vector<int> &ratings) {
    int candies = 0;
    int size = ratings.size();
    vector<int> lefttoright(size, 1);
    vector<int> righttoleft(size, 1);
    
    for (auto l = 1; l<size; ++l)
        if (ratings[l] > ratings[l-1])
            lefttoright[l] = lefttoright[l-1] + 1;
    
    for (auto r = size-2; r>=0; --r)
        if (ratings[r] > ratings[r+1])
            righttoleft[r] = righttoleft[r+1] + 1;
            
    for (auto i = 0; i<size; ++i)
        candies += max(lefttoright[i], righttoleft[i]);
        
    return candies;
}
