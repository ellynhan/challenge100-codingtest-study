import sys

input = sys.stdin.readline

n, c = map(int, input().split())

arr = [int(input()) for _ in range(n)]
arr.sort()

start = 1
end = arr[-1] - arr[0]
ans = 0

def binarySearch(arr, start, end):
    while start <= end:
        mid = (start + end) // 2
        current = arr[0]
        cnt = 1
        
        for i in range(1, len(arr)):
            if arr[i] >= current + mid:
                cnt += 1
                current = arr[i]
                
        if cnt >= c:
            global ans
            start = mid + 1
            ans = mid
        else:
            end = mid - 1



binarySearch(arr, start, end)
print(ans)
