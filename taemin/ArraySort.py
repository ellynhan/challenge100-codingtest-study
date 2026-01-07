# 2025.12.22 문제1 배열 정렬하기
# [ETC] ArraySort/배열정렬/10분
# 도전 : 내장함수 사용금지
arr = list(map(int, input().split()))
n = len(arr)

for i in range(n-1):
    for j in range(n-1-i):
        if arr[j] > arr[j+1]:
            arr[j], arr[j+1] = arr[j+1], arr[j]

print(arr)

# 내장함수 sorted 사용후 재풀이
arr = list(map(int, input().split()))
arr = sorted(arr)
print(arr)
