import sys

N,R,C = map(int, sys.stdin.readline().split())
ans = 0

def solve(n,r,c):
    global ans
    global R, C

    if(r == R and c == C):
        print(ans)
        return

    if(r <= R and r + n > R and c <= C and c + n > C):
        solve(n / 2, r, c)
        solve(n / 2, r, c + n / 2)
        solve(n / 2, r + n / 2, c)
        solve(n / 2, r + n / 2, c + n / 2)
    else:
        ans += int(n * n)
    
    '''
    if(n == 2):
        if(r == R and c == C):
            #print("same!")
            print(ans)
            return
        ans += 1

        if(r == R and c + 1 == C):
            print(ans)
            return
        ans += 1

        if(r + 1 == R and c == C):
            print(ans)
            return
        ans += 1

        if(r + 1 == R and c + 1 == C):
            print(ans)
            return
        ans += 1

        #print(ans)

        return
    '''

#print(pow(2,N))
solve(pow(2,N), 0, 0)
