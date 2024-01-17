n = int(input())
arr = list(input())

colors = {'B': 0, 'R': 0}
colors[arr[0]] += 1  # 처음 색 칠하기
for i in range(1, n):
    if arr[i] != arr[i - 1]:
        colors[arr[i]] += 1

answer = min(colors['B'], colors['R']) + 1
print(answer)
