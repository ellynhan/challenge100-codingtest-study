import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

S = int(input())

cnt = 0
sum = 0

while True:
    cnt += 1
    sum += cnt
    if sum > S:
        break

print(cnt-1)

