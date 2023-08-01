#https://www.acmicpc.net/problem/1931
# 1트 실패 : 회의시간 짧다고 best가 아님
# 2트 : 끝나는 시간 정렬

N = int(input())
candidate = []
for i in range(N):
    start, end = input().split(" ")
    candidate.append((int(start), int(end)))

candidate.sort(key = lambda x: x[0])
candidate.sort(key = lambda x: x[1])

answer = []
left = 0
for start, end in candidate:
    if left <= start:
        left = end
        answer.append((start,end))
# print(candidate)
print(len(answer))