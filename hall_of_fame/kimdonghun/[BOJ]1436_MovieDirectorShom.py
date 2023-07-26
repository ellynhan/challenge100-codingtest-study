import sys

N = int(sys.stdin.readline())
cnt = 0
cur_num = 666

while cnt < N-1:
    cur_num += 1

    if str(cur_num).find("666") != -1:
        cnt += 1
    
print(cur_num)
    