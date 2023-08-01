class Solution:
    def isPalindrome(self, s: str) -> bool:         ## vaild char n, space m
        
        s = s.lower()           ## 일단 소문자 바꾸기
        left = 0                ## idx 왼쪽
        right = len(s) - 1      ## 오른쪽

        while left < right:         ## left < right        
            leftChar = s[left]      ## char
            rightChar = s[right]    ## char

            while not ((97 <= ord(leftChar) <= 122) or (48<= ord(leftChar) <= 57)):## a=97, z=122 0=48, 9=57
                left += 1
                if left > right:   # ",."
                    return True
                leftChar = s[left]
            
            while not ((97 <= ord(rightChar) <= 122) or (48 <= ord(rightChar) <= 57)):  ## a = 97, z =122
                right -= 1
                if left > right:
                    return True
                rightChar = s[right]

            
            if not (rightChar == leftChar):
                return False
            else:
                left += 1
                right -= 1

        

        return True