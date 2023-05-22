class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        map = {}
        t_map = {}
        if (len(s) != len(t)):
            return False
        else:
            for i in s:
                if i in map:
                    map[i] += 1
                else:
                    map[i] = 1
            for i in t:
                if i not in map:
                    return False
                else:
                    if i in t_map:
                        t_map[i] += 1
                    else:
                        t_map[i] = 1
            # print(t_map, map)
            for i in t_map:
                if t_map[i] != map[i]:
                    return False
            return True

# sol = Solution()
# print(sol.isAnagram("anagram", "nagaram"))
