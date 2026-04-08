class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {}
        l = 0
        res = 0
        
        for r in range(0, len(s)):
            if s[r] in mp:
                l = max(l, mp[s[r]] + 1)

            mp[s[r]] = r
            res = max(res, r - l + 1)
        return res