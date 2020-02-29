class Solution
{
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        
        while (end - start > 1)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                end = mid;
            else if (nums[mid] > target)
                end = mid;
            else if (nums[mid] < target)
                start = mid;
        }
        if (nums[start] == target)
            return start;
        if (nums[end] == target)
            return end;
        return -1;
    }
};
