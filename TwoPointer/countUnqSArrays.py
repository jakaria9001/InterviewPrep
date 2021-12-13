class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        temp, i, j, count = [], 0, 0, 0
        while i < len(A):
            if j < len(A) and A[j] not in temp:
                temp.append(A[j])
                j += 1
            else:
                count = (count + j - i) % (10 ** 9 + 7)
                temp.remove(A[i])
                i += 1
        return count 
