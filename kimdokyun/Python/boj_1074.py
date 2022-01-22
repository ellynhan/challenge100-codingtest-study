def choose(N,r,c):
    if N==0: return 0
    else:
        cutLine = 2**(N-1)
        if r < cutLine and c < cutLine:
            return choose(N-1,r,c)
        elif r < cutLine and c >= cutLine:
            return cutLine**2 + choose(N-1,r,c-cutLine)
        elif r >= cutLine and c < cutLine:
            return 2*(cutLine**2) + choose(N-1,r-cutLine,c)
        else:
            return 3*(cutLine**2) + choose(N-1,r-cutLine,c-cutLine)
N,r,c = map(int,input().split())
print(choose(N,r,c))
