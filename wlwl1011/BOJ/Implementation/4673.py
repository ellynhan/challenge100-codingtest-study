import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

def d(n):
    split_sum = 0
    copy_n = n
    while copy_n:
        split_sum += copy_n % 10
        copy_n = copy_n // 10
    return n + split_sum
    
check = set()
for i in range(1,10001):
    ans = d(i)
    if ans and ans <= 10000:
        check.add(ans)

for i in range(1,10001):
    if i not in check:
        print(i)
