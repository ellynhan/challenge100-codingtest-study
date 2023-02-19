class Solution:
    def minWindow(self, s: str, t: str) -> str:

        left = 0
        minLen = float("inf")
        ans = ""
        cnt = {}
        tcnt = {}

        for char in t:  ## t 내의 빈도 저장
            tcnt[char] = 1 + tcnt.get(char, 0)
        # print(tcnt)

        vaild = True
        for right in range(len(s)): 
            cnt[s[right]] = 1 + cnt.get(s[right], 0)    ## window 내의 빈도 저장
            # print("cnt: ",cnt)
            for char, num in tcnt.items():
                check = False
                # print(char, char in cnt.keys())

                if char not in cnt.keys():
                    check = False
                    break
                elif cnt[char] == 0 or cnt[char] < num:
                    check = False
                    break
                else:
                    check = True


            # print(check)
            if check:
                vaild = True
            else:
                vaild = False
            ## 다 있으면 vaild True, 하나라도 없으면 false
            # print("========================")
            while vaild:
                # print("---------while----------")
                # print(left, right+1)
                window = s[left: right+1]
                # print("window: ",window)
                winLen = len(window)

                if winLen < minLen:
                    minLen = winLen
                    ans = window

                # print(cnt)
                # print(s[left])
                cnt[s[left]] -= 1
                left += 1

                # print(cnt)
                for char, num in tcnt.items():
                    if char not in cnt.keys() or cnt[char] < 1:
                        vaild = False
                        break
                    elif cnt[char] < 1 or cnt[char] < num:
                        vaild = False
                        break

            # print("-------endwhile--------")
            # print(s[left:right+1])
            # print("out")

            # print("=======endfor======")
                
        

        
        return ans