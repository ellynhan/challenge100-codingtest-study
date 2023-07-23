n, m = map(int, input().split())
time = list(map(int, input().split()))

answer = 0
l, r = max(time), sum(time)
while l <= r:
    mid = (l+r)//2
    disk, size = 1, 0
    for t in time:
        if size + t > mid:
            disk += 1
            size = 0
        size += t
    if disk <= m:
        answer = mid
        r = mid-1
    else:
        l = mid+1
print(answer)
