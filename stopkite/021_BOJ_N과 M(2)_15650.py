n, m = map(int, input().split())
temp = []


def dfs(st):
    if len(temp) == m:
        print(' '.join(map(str, temp)))
        return

    for num in range(st, n + 1):
        if num in temp:
            continue
        temp.append(num)
        dfs(num + 1)
        temp.pop()


dfs(1)
