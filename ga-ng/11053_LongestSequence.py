import sys

input = sys.stdin.readline

n = int(input())

lst = list(map(int, input().split()))

dp = [1] * n    ## 모든 수열은 자기 자신부터 시작할 수 있으므로 1로 초기화 한다.

for i in range(1, n):   ## 각각의 인덱스를 참조하자
    for j in range(i):      ## 해당 인덱스 이전의 것들을 보자
        if lst[i] > lst[j]: ## 만약 해당 인덱스보다 작은 j 가 있다고 하면, 수열을 만들것이다.
            dp[i] = max(dp[i], dp[j]+1) ## 그럼 해당 인덱스는 자기 그대로던가, dp[j]+1 즉 가장 긴 수열이다.
        # print(dp)
    

print(max(dp))