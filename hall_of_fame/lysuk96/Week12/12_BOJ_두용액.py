# 투포인터 사용
# https://www.acmicpc.net/problem/2470
N = int(input())
liquids = list(map(int, input().split(" ")))
liquids.sort()

lo = 0
hi = N-1
m = 2000000001
answer = []
while lo<hi:
    now = liquids[lo] + liquids[hi]
    if abs(now) < m:
        answer = [liquids[lo], liquids[hi]]
        m = abs(now)

    if now == 0:
        break
    elif now > 0:
        hi-=1
    else: lo+=1
print(*answer)
