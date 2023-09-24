def diff_check(a, b):
    l = 0
    for i in range(len(a)):
        if a[i] == b[i]:
            l += 1
    if l == len(a) - 1:
        return True
    else:
        return False


def dfs(current, target, words, visit, depth, ans):
    if current == target:
        ans.append(depth)
        return

    for i in range(len(words)):
        if not visit[i]:
            if diff_check(current, words[i]):
                visit[i] = 1
                dfs(words[i], target, words, visit, depth + 1, ans)
                visit[i] = 0


def solution(begin, target, words):
    if target not in words:
        return 0

    visit = [0] * len(words)
    ans = []
    dfs(begin, target, words, visit, 0, ans)
    if ans:
        return min(ans)
    else:
        return 0