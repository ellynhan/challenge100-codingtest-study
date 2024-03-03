import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
import math
H, W, N, M = map(int, input().split())

print(math.ceil(H/(N+1))*math.ceil(W/(M+1)) )
                