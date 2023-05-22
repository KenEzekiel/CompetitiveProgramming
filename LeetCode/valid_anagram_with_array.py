class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        list = [0 for i in range(26)]
        for i in s:
            list[ord(i) - 97] += 1
        for i in t:
            list[ord(i) - 97] -= 1

        return list == [0 for i in range(26)]

sol = Solution()
print(sol.isAnagram("anagram", "nagaram"))
