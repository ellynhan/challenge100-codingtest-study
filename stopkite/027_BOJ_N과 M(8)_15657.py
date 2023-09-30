n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

temp = []


def dfs(cur_idx):
    if len(temp) == m:
        print(' '.join(map(str, temp)))
        return

    for i in range(cur_idx, len(arr)):
        temp.append(arr[i])
        dfs(i)
        temp.pop()


dfs(0)
