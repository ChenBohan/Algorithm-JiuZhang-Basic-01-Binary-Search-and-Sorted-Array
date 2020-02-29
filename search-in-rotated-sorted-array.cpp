class Solution
{
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target)
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
            if (A[mid] == target)
            {
                return mid;
            }
            if (A[mid] > A[start])
            {
                if (A[start] <= target && A[mid] > target)
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }
            else
            {
                if (A[end] >= target && A[mid] < target)
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
        }
        if (A[start] == target)
        {
            return start;
        }
        else if (A[end] == target)
        {
            return end;
        }
        else
        {
            return -1;
        }
    }
};
