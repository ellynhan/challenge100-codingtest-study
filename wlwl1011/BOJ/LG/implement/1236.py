N, M = map(int, input().split())
arr = []

for _ in range(N):
    arr.append(list(input()))

row_has_guard = [False] * N
col_has_guard = [False] * M

# 각 행과 열에 경비원이 있는지 확인
for i in range(N):
    for j in range(M):
        if arr[i][j] == 'X':
            row_has_guard[i] = True
            col_has_guard[j] = True

row_guards_needed = N - sum(row_has_guard)
col_guards_needed = M - sum(col_has_guard)

# 경비원을 추가해야 하는 횟수를 최소화
guards_needed = max(row_guards_needed, col_guards_needed)

print(guards_needed)