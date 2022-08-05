import sys

input = sys.stdin.readline

n = int(input())

A = list(map(int, input().split()))

temp = [0]

for a in A:
    if temp[-1] < a:  ## temp 의 마지막 요소보다 지금 열람중인 a가 더 크면?
        temp.append(a)  ## 그냥 넣으면 됨
    else:               ## temp 의 마지막 요소보다 지금 열람중이 a가 작은 경우라면?
        start = 0
        end = len(temp)
        
        while start < end:
            mid = (start + end) // 2
            
            if temp[mid] < a:   ## 만일 어떤 temp[mid] 보다 a가 더 크면?
                start = mid + 1 ## mid + 1 해서 찾기
            else:
                end = mid   ## end = mid
        
        temp[end] = a       ## temp 의 end 는 a 가 되도록 한다.

print(len(temp) - 1)