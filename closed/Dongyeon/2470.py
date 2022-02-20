#백준 2470번 두 용액
# 골드 5
N = int(input())

lq = list(map(int, input().split()))
lq.sort()
print(lq)
s = 0
e = N-1
best = lq[s] + lq[e]
best_s = s
best_e = e
while (s<e):
    sum = lq[s] + lq[e]
    if sum ==0 :
        best_s = s
        best_e = e
        break
    elif sum>0:
        if abs(best) > abs(sum):
            best_s = s
            best_e = e
            best = sum
        e -=1
    else:
        if abs(best) > abs(sum):
            best_s = s
            best_e = e
            best = sum
        s += 1

print(lq[best_s], lq[best_e])
