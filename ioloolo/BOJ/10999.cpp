import sys


def init(arr, tree, node, start, end):
    if start == end:
        tree[node] = arr[start]
        return
    mid = (start + end) // 2
    init(arr, tree, node * 2, start, mid)
    init(arr, tree, node * 2 + 1, mid + 1, end)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


def update_lazy(tree, lazy, node, start, end):
    if lazy[node] != 0:
        tree[node] += (end - start + 1) * lazy[node]
        if start != end:
            lazy[node * 2] += lazy[node]
            lazy[node * 2 + 1] += lazy[node]
        lazy[node] = 0


def update_range(tree, lazy, node, start, end, idx_start, idx_end, dif):
    update_lazy(tree, lazy, node, start, end)
    if idx_start > end or start > idx_end:
        return
    if start >= idx_start and idx_end >= end:
        tree[node] += (end - start + 1) * dif
        if start != end:
            lazy[node * 2] += dif
            lazy[node * 2 + 1] += dif
        return
    mid = (start + end) // 2
    update_range(tree, lazy, node * 2, start, mid, idx_start, idx_end, dif)
    update_range(tree, lazy, node * 2 + 1, mid + 1, end, idx_start, idx_end, dif)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


def sum_range(tree, lazy, node, start, end, left, right):
    update_lazy(tree, lazy, node, start, end)
    if left > end or start > right:
        return 0
    if start >= left and right >= end:
        return tree[node]
    mid = (start + end) // 2
    return sum_range(tree, lazy, node * 2, start, mid, left, right) + sum_range(tree, lazy, node * 2 + 1, mid + 1, end,
                                                                                left, right)


input = sys.stdin.readline
n, m, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]
val = [list(map(int, input().split())) for _ in range(m + k)]
tree_list = [0] * (n * 4)
lazy = [0] * (n * 4)

init(arr, tree_list, 1, 0, n - 1)

for v in val:
    b, c = v[1], v[2]
    if v[0] == 1:
        d = v[3]
        update_range(tree_list, lazy, 1, 0, n - 1, b - 1, c - 1, d)
    else:
        print(sum_range(tree_list, lazy, 1, 0, n - 1, b - 1, c - 1))

