import sys

input = sys.stdin.readline


def union(a, b):
    parent_a, parent_b = find(a), find(b)

    if parent_a < parent_b:
        parent[parent_b] = parent_a
    else:
        parent[parent_a] = parent_b


def find(k):
    if k != parent[k]:
        parent[k] = find(parent[k])

    return parent[k]


def canMove(iterables):
    p = find(iterables[0])
    for cur_p in iterables[1:]:
        if p != find(cur_p):
            return False
    return True


if __name__ == "__main__":
    N = int(input())  # 도시의 수 <= 200
    M = int(input())  # 여행 계획에 속한 도시들의 수 <= 1000

    parent = [i for i in range(N + 1)]

    for i in range(1, N + 1):
        for _j, v in enumerate(map(int, input().split())):
            if v == 0:
                continue
            j = _j + 1
            union(i, j)

    plan = list(set(map(int, input().split())))

    if canMove(plan):
        print("YES")
    else:
        print("NO")
