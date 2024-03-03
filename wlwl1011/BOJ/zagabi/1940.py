import sys
input = lambda : sys.stdin.readline().strip()

def find(target, start):
    end = N - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return False

N = int(input())
M = int(input())
arr = list(map(int, input().split()))

arr.sort()
count = 0
for i in range(N):
    number = M - arr[i]
    # 두 번째 재료는 i+1부터 N-1까지의 인덱스에서 찾습니다.
    if number != arr[i] and find(number, i+1):
        count += 1

print(count)
