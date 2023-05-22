from ast import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        set_num = set()
        for i in nums:
            if set_num.__contains__(i):
                return True
            else:
                set_num.add(i)
        return False

