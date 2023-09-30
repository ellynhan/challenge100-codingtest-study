n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

temp = []


def dfs(cur_idx):
    if len(temp) == m:
        print(' '.join(map(str, temp)))
        return

    prev = 0
    for i in range(cur_idx, n):
        if prev != arr[i]:
            temp.append(arr[i])
            dfs(i)
            prev = arr[i]
            temp.pop()


dfs(0)
