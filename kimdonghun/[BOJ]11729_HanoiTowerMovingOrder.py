import sys

n_count = 0
process_l = []

def hanoiTower(N, source, by, dest):
    global n_count
    if(N == 1):
        n_count += 1
        process_l.append([source, dest])
    else:
        hanoiTower(N-1, source, dest, by)
        n_count += 1
        process_l.append([source, dest])
        hanoiTower(N-1, by, source, dest)

N = int(sys.stdin.readline())
hanoiTower(N, 1,2,3)
print(n_count)

for i in range(len(process_l)):
    for j in process_l[i]:
        print(j, end = ' ')
    print()