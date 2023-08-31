
from ast import List


class Solution:
    def bn(self, nums, target, idx):
        if len(nums) == 1:
            if nums[0] == target:
                return idx
            else:
                return -1
        else:
            n = int(len(nums)/2)
            left = nums[:n]
            right = nums[n:]
            print(left, right, n)
            if nums[n] == target:
                return n + idx
            elif nums[n] < target:
                print(nums[n], "<", target, n)
                return self.bn(right, target, n + idx)
            elif nums[n] > target:
                print(nums[n], ">", target, n)
                return self.bn(left, target, idx)            
            

    def search(self, nums, target: int) -> int:
        return self.bn(nums, target, 0)
    
sl = Solution()

nums = [-1,0,3,5,9,12]
target = 9

print(sl.search(nums, target))

