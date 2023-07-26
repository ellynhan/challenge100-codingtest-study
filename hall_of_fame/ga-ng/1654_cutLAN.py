import sys

input = sys.stdin.readline

k, n = map(int, input().split())

lan = [int(input().rstrip()) for _ in range(k)]


start = 1
end = max(lan)

res = 0
cuttedLan = 0

while(start <= end):
    lanNum = 0      ## 처음엔 0 이라고 하자
    mid = (start + end) // 2    ## 중간 지점은 이렇게 정의한다.
    # print(mid)
    
    for x in lan:               ## 각각의 랜선을 하나씩 살펴보자
        cuttedLan = x // mid
        # print(cuttedLan)
        lanNum += cuttedLan
    # print()
    
    if lanNum < n:
        end = mid - 1
    else:
        res = mid
        start = mid + 1
        
print(res)