class Solution
{
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &nums, int target)
    {
        int start, mid, end;
        start = 0;
        end = nums.size() - 1;
        
        if (nums.empty())
        {
            return 0;
        }
        
        if (nums[end] < target)
        {
            return end + 1;
        }
        
        while(end - start > 1)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                end = mid;
            }
            if (nums[mid] > target)
            {
                end = mid;
            }
            if (nums[mid] < target)
            {
                start = mid;
            }
        }
        if (nums[start] >= target)
        {
            return start;
        }
        else if (nums[end] >= target)
        {
            return end;
        }
    }
};
