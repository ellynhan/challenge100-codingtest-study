value = [0]*200000
N,K=map(int,input().split())
bfs = [N]
while bfs:
    now = bfs.pop(0)
    if now == K: break
    else :
        nexts = [now-1,now+1,now*2]
        for next in nexts:
            if next < 0 or (next > 2*K and next > now): continue
            if value[next]==0 and next!=N:
                bfs.append(next)
                value[next] = value[now]+ 1
print(value[K])