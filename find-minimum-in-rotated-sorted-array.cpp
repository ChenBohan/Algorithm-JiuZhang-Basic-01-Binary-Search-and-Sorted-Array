class Solution
{
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &A)
    {
        int start, mid, end;
        if (A.empty())
        {
            return -1;
        }
        start = 0;
        end = A.size() - 1;
        while(end - start > 1)
        {
            mid = start + (end - start) / 2;
            if (A[mid] >= A[start] && A[mid] > A[end])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        if (A[start] <= A[end])
        {
            return A[start];
        }
        else
        {
            return A[end];
        }
    }
};
