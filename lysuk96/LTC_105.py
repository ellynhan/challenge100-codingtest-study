'''
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
'''

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.upper()
        i = 0
        j = len(s)-1
        while(i < j) :
            if (s[i].isalnum() == False):
                i +=1
            elif (s[j].isalnum() == False):
                j -=1
            else:
                if(s[i] == s[j]):
                    print(s[i])
                    i+=1
                    j-=1
                else:
                    return False
        return True

solution = Solution()
s = input()
print(solution.isPalindrome(s))

