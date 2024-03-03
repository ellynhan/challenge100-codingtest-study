n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

visited = [False] * n
temp = []


def dfs(cur_idx):
    if len(temp) == m:
        print(' '.join(map(str, temp)))
        return

    prev = 0
    for i in range(cur_idx, n):
        if not visited[i] and prev != arr[i]:
            visited[i] = True
            temp.append(arr[i])
            prev = arr[i]
            dfs(i)
            visited[i] = False
            temp.pop()

dfs(0)
