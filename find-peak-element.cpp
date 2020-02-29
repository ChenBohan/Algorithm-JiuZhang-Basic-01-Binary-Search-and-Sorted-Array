class Solution
{
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A)
    {
        int start = 0, end = A.size() - 2;
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            {
                return mid; //A[mid] is peak element
            }
            
            if (A[mid - 1] < A[mid])
            {
                start = mid; //上坡
            }
            
            if (A[mid] > A[mid + 1])
            {
                end = mid; //下坡
            }
            
            if (A[mid - 1] > A[mid] && A[mid] < A[mid + 1])
            {
                end = mid; //A[mid]在波谷
            }
        }
        
        if (A[start] < A[end])
        {
            return end;
        }
        else
        {
            return start;
        }
        return -1;
    }
};
