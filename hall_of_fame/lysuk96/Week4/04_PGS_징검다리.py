#https://programmers.co.kr/learn/courses/30/lessons/43236
# 실패
# mid = (n개 지웠을 때 돌간격의 최솟값) (return할 정답)
# 정답은 이거야!라고 짱박고 이분탐색으로 찾다가 -> 최솟값의 최댓값이므로 그중 가장 오른쪽거 return

def solution(distance, rocks, n):
    rocks.sort()
    left = 1
    right = distance
    answer = 0
    
    while left <= right :
        mid = (left+right)//2
        # print('mid', mid)
        now = 0
        eli_count = 0
        for rock in rocks:
            if (rock-now) >= mid:
                now = rock
                # print(now)
            else:
                eli_count+=1
            
        if eli_count > n :
            right = mid - 1
        elif eli_count <= n:
            left = mid + 1
            answer = mid
    
    return answer