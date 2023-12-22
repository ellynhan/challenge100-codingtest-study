import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def union(a, b):
    parent_a, parent_b = find(a), find(b)

    if a < b:
        lst[parent_b] = parent_a
    else:
        lst[parent_a] = parent_b


def find(k):
    if lst[k] != k:
        lst[k] = find(lst[k])

    return lst[k]


def isSameUnion(a, b):
    return find(a) == find(b)


if __name__ == "__main__":
    n, m = map(int, input().split())

    lst = list(range(n + 1))
    answers = []

    for _ in range(m):
        oper, a, b = map(int, input().split())

        if oper == 0:
            union(a, b)

        elif oper == 1:
            answers.append("YES" if isSameUnion(a, b) else "NO")

    for answer in answers:
        print(answer)
