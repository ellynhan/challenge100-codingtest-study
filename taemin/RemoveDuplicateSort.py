# 2025.12.22 문제2 중복 제거 후 내림차순 정렬
# [ETC] RemoveDuplicateSort/중복제거정렬/10분
# 도전 : 내장함수 사용금지
arr = list(map(int, input().split()))
unique = []

for x in arr:
    if x not in unique:
        unique.append(x)

n = len(unique)

for i in range(n-1):
    for j in range(n-1-i):
        if unique[j] < unique[j+1]:
            unique[j], unique[j+1] = unique[j+1], unique[j]

print(unique)
