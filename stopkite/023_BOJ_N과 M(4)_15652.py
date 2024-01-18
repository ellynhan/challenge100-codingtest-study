n, m = map(int, input().split())
temp = []


def dfs(cur_num):
    if len(temp) == m:
        print(' '.join(map(str, temp)))
        return

    for i in range(cur_num, n + 1):
        temp.append(i)
        dfs(i)
        temp.pop()


dfs(1)
