import sys
input = sys.stdin.readline

def init(s, e, node):
    if s == e:
        tree[node] = arr[s]
    else:
        mid = (s+e)//2
        tree[node] = min(init(s, mid, node*2), init(mid+1, e, node*2+1))
    return tree[node]

def find_min(s, e, node, l, r):
    if e < l or r < s: return 1e9+1
    if l <= s and e <= r: return tree[node]
    mid = (s+e)//2
    return min(find_min(s, mid, node*2, l, r), find_min(mid+1, e, node*2+1, l, r))

n, m = map(int, input().split())
arr = [int(input()) for _ in range(n)]
tree = [0] * (n*4)
init(0, n-1, 1)
for _ in range(m):
    a, b = map(int, input().split())
    print(find_min(0, n-1, 1, a-1, b-1))
