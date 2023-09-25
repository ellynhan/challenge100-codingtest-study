import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, M, B = map(int, input().split())
block = []

for _ in range(N):
    block.append(list(map(int, input().split())))

ans = int(1e9)
glevel = 0

for i in range(257):
    use_block = 0
    take_block = 0
    for x in range(N):
        for y in range(M):
            if block[x][y] > i:
                take_block += block[x][y] - i
            else:
                use_block += i - block[x][y]
    if use_block > take_block + B:
        continue

    count = take_block * 2 + use_block

    if count <= ans:
        ans = count
        glevel = i

print(ans, glevel)






    
