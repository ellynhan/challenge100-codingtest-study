import sys
input = sys.stdin.readline

n, q = map(int, input().split())
arr = list(map(int, input().split()))
tree = [0] * n * 4

# 세그먼트 트리 초기화 (구간 합 구해 놓기)
# s: 현재 구간 배열의 시작, e: 현재 구간 배열의 마지막
# node: 현재 노드 (노드 번호는 1부터 시작함)
def init(s, e, node):
    # 리프 노드면 해당 값 삽입
    if s == e:
        tree[node] = arr[s]
        return tree[node]
    mid = (s+e)//2
    # 왼쪽 자식 노드와 오른쪽 자식 노드를 채운 뒤, 부모 노드에 값을 채운다.
    tree[node] = init(s, mid, node*2) + init(mid+1, e, node*2+1)
    return tree[node]

# 구간 합을 구하는 함수
# s: 현재 구간 배열의 시작, e: 현재 구간 배열의 끝
# node: 현재 노드 (노드 번호는 1부터 시작함)
# l: 구하려는 구간 합의 왼쪽 끝, r: 구하려는 구간 합의 오른쪽 끝
def prefix_sum(s, e, node, l, r):
    # 범위를 벗어나면, 더할 필요 없음
    if l > e or r < s: return 0
    # 범위 내에 완전히 포함 되면, 더 깊이 안가고 리턴
    if l <= s and e <= r: return tree[node]
    # 그렇지 않으면 배열을 두 부분으로 나누면서,
    mid = (s+e)//2
    # 재귀를 수행하며 구간에 해당하는 부분을 더해 나간다.
    return prefix_sum(s, mid, node*2, l, r) + prefix_sum(mid+1, e, node*2+1, l, r)

# 특정 원소 값 변경 함수
# 해당 원소를 포함하는 모든 구간 합 노드들을 갱신한다.
# idx: 변경할 원소의 인덱스
# diff: 이전 값과 변경할 값의 차이
def update(s, e, node, idx, diff):
    # 변경할 idx가 범위 밖이면 탐색할 필요 없음
    if idx < s or e < idx: return
    # 범위 내에 있으면 차이를 더해 갱신
    tree[node] += diff
    # 현재 노드가 리프 노드가 아니면 자식들도 갱신
    if s != e:
        mid = (s+e)//2
        update(s, mid, node*2, idx, diff)
        update(mid+1, e, node*2+1, idx, diff)

init(0, n-1, 1)
for _ in range(q):
    x, y, a, b = map(int, input().split())
    if x > y: x, y = y, x
    print(prefix_sum(0, n-1, 1, x-1, y-1))
    update(0, n-1, 1, a-1, b-arr[a-1])
    arr[a-1] = b
