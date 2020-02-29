class Solution
{
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start, mid, end;
        vector<int> bound;
        
        if (nums.empty())
        {
            bound.push_back(-1);
            bound.push_back(-1);
            return bound;
        }
        
        // search for left bound
        start = 0;
        end = nums.size() - 1;
        while (end - start > 1)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                end = mid;
            else if (nums[mid] > target)
                end = mid;
            else if (nums[mid] < target)
                start = mid;
        }
        if (nums[start] == target)
            bound.push_back(start);
        else if (nums[end] == target)
            bound.push_back(end);
        else
        {
            bound.push_back(-1);
            bound.push_back(-1);
            return bound;
        }
        
        // search for right bound
        start = 0;
        end = nums.size() - 1;
        while (end - start > 1)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                start = mid;
            else if (nums[mid] > target)
                end = mid;
            else if (nums[mid] < target)
                start = mid;
        }
        if (nums[end] == target)
            bound.push_back(end);
        else if (nums[start] == target)
            bound.push_back(start);
            
        return bound;
    }
};
