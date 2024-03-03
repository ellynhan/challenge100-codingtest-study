import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
import math

N = int(input())

nums_pileup = 1
cnt = 1
while True:
    if nums_pileup >= N:
        break
    nums_pileup += 6 * cnt
    cnt += 1
print(cnt)    

