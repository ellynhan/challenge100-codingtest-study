import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

K = int(input())
answer = []
for _ in range(K):
    temp = int(input())
    if temp:
        answer.append(temp)
    else:
        answer.pop()

print(sum(answer))
