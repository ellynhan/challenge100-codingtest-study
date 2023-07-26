from collections import defaultdict
from bisect import insort,bisect_right

# def is_pruning(a, b):
#     if abs(b - a) <= K:
#         return True
#     return False

def find(x):
    idx = bisect_right(keys, x)
    if idx == 0:
        right = keys[idx]
        if x - right <= K:
            return right
    elif idx == len(keys):
        left = keys[idx-1]
        if x - left <= K:
            return left
    else:
        left = keys[idx-1]
        right = keys[idx]
        if right -x <= K or x-left <= K:
            if right -x == x - left:
                return '?'
            elif x - left < right -x:
                return left
            else:
                return right
    return -1

N, M, K = map(int, input().split(" "))
dic = defaultdict(int)
keys = []
for _ in range(N):
    a, b = map(int, input().split(" "))
    dic[a] = b
    insort(keys, a)
for _ in range(M):
    command, *tmp = map(int , input().split(" "))
    if command == 1:
        dic[tmp[0]] = tmp[1]
        insort(keys, tmp[0])
    elif command == 2:
        now = find(tmp[0])
        if now != '?' and now != -1:
            dic[now] = tmp[1]
        # print(dic)
    elif command ==3:
        now = find(tmp[0])
        if now != '?' and now != -1:
            print(dic[now])
        else:
            print(now)