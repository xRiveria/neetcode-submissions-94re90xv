class Solution:
    def isPalindrome(self, s: str) -> bool:
        d = "".join(c.lower() for c in s if c.isalnum())
        return d == d[::-1]