class Solution:
    def minWindow(self, s: str, t: str) -> str:

        left = 0
        minLen = float("inf")
        ans = ""
        cnt = {}
        tcnt = {}


        for char in t:  ## t 내의 빈도 저장
            tcnt[char] = 1 + tcnt.get(char, 0)

        have, need = 0, len(tcnt)

        vaild = False
        for right in range(len(s)): 
            cnt[s[right]] = 1 + cnt.get(s[right], 0)    ## window 내의 빈도 저장

            if s[right] in tcnt.keys() and cnt[s[right]] == tcnt[s[right]]:
                have += 1


            while have == need:
                window = s[left: right+1]
                winLen = len(window)

                if winLen < minLen:
                    minLen = winLen
                    ans = window

                cnt[s[left]] -= 1

                if s[left] in tcnt.keys() and cnt[s[left]] < tcnt[s[left]]:
                    have -= 1

                left += 1

        return ans