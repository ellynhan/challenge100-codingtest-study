class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        n1 = 0
        n2 = 0
        
        for len1 in num1:
            n1 = n1*10 + int(len1)
        
        for len2 in num2:
            n2 = n2*10 + int(len2)

        return str(n1+n2)