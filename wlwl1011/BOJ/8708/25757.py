import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, G = input().split()
N = int(N)

person = set()

for i in range(N):
    name = input()
    person.add(name)


# 윷놀이 $Y$, -> 2
# 같은 그림 찾기 $F$, -> 3
# 원카드 $O$가 -> 4

if G == 'Y':
    print(len(person))

elif G == 'F':
    print(len(person)//2)
else:
    print(len(person)//3)