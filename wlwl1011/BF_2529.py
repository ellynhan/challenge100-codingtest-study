import sys, os, io, atexit
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

def check(i,j,k):
    if k=='>':
        return i>j
    else:
        return i<j    

def solve(depth, s):
    global max_value
    global min_value

    if depth == K+1:
        if len(min_value) == 0:
            min_value = s
        else:
            max_value = s
        return
    for i in range(10):
        if not visited[i]:
            if depth == 0 or check(s[-1],str(i),arr[depth-1]):
                visited[i] = True
                solve(depth+1,s+str(i))
                visited[i] = False            


K = int(input())
arr = list(map(int, input().split()))
visited = [0] * 10

max_value = ''
min_value = ''

solve(0, '')
print(max_value)
print(min_value)





