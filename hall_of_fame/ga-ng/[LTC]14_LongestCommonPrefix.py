class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        ans = []
        check = True

        for i in range(len(min(strs))): ## 0~3
            char = strs[0][i] ## f l o w

            for j in range(1, len(strs)): ## 0 1 2
                if char != strs[j][i]:
                    check = False
                    break

            
            if check == False:
                break
            else:
                ans.append(strs[0][i])

        
        return "".join(ans)