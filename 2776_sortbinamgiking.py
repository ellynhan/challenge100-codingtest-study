import sys

def bi_search(target,data):
    start = 0
    end = len(data)-1

    while start <= end:
        mid = (start+end)//2

        if data[mid] == target:
            return 1
        elif data[mid] < target:
            start = mid+1
        else:
            end = mid-1

    return 0


t = int(sys.stdin.readline().rstrip())

for _ in range(t):
    n = int(sys.stdin.readline().rstrip())

    diary1 = sys.stdin.readline().rstrip().split()
    diary1.sort()

    m = sys.stdin.readline().rstrip()

    diary2 = sys.stdin.readline().rstrip().split()

    for i in diary2:
        if bi_search(i,diary1):
            print(1)
        else:
            print(0)
