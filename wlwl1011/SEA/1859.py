T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    li = list(map(int, input().split()))
 
    # 뒤에서 부터 편하게 탐색하기 위해 문자열 전체 역순화
     
    profit = 0
    curr = li[N-1]
    for val in li[::-1]:
        if curr > val:
            profit += (curr - val)
        else:
            curr = val
 
    print("#", test_case, " ", profit, sep="")
