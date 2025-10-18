
from typing import List


class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:

        changesEven = 0
        changesOdd = 0

        cpyNums = nums.copy()

        for i in range(len(nums)):
            if i%2 == 0:
                if i + 1 < len(nums) and nums[i] <= nums[i+1]:
                    diff = abs(nums[i+1] - nums[i] + 1)
                    changesEven += diff
                    nums[i+1] -= diff
                if i-1 >= 0 and nums[i] <= nums[i-1]:
                    diff = abs(nums[i-1] - nums[i] + 1)
                    changesEven += diff
                    nums[i-1] -= diff

            #print(nums)
        
        for i in range(len(cpyNums)):

            if i%2 != 0:
                if i + 1 < len(cpyNums) and cpyNums[i] <= cpyNums[i+1]:
                    diff = abs(cpyNums[i+1] - cpyNums[i] + 1)
                    changesOdd += diff
                    cpyNums[i+1] -= diff
                if i-1 >= 0 and cpyNums[i] <= cpyNums[i-1]:
                    diff = abs(cpyNums[i-1] - cpyNums[i] + 1)
                    changesOdd += diff
                    cpyNums[i-1] -= diff


        return min(changesOdd, changesEven)
        


nums = [7,4,8,9,7,7,5]
print(Solution().movesToMakeZigzag(nums))