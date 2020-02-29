class Solution
{
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int count = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = n - 1;
        int j = 0;
        
        while (i >= 0 && j < m)
        {
            if (matrix[i][j] == target)
            {
                count++;
                i--;
                j++;
            }
            else if (matrix[i][j] > target)
            {
                i--;
            }
            else if (matrix[i][j] < target)
            {
                j++;
            }
        }
        return count;
    }
};
