K = int(input())
tree = list(map(int, input().split()))
node_cnt = max(tree)+1
pNodes = [-1] * node_cnt

pNodes[tree[0]] = tree[0]
for i in range(1, len(tree)):
    if pNodes[tree[i]] == -1:
        pNodes[tree[i]] = tree[i-1]
pNodes[tree[0]] = -1

print(node_cnt)
print(*pNodes)