import math

class Solution:
    """
    @param nums: a rotated sorted array
    @return: the minimum number in the array
    """
    def findMin(self, nums):
        # write your code here
        min = math.inf
        for num in nums:
            if num < min:
                min = num
        return min
