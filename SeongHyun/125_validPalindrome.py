class Solution:
    def isPalindrome(self, s: str) -> bool:
        pylist = []

        for char in s:
            if char.isalnum():
                pylist.append(char.lower())
        
        return pylist == pylist[::-1]
