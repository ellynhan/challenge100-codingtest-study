import sys
from functools import cmp_to_key

def time_compare(a,b):
    if a[1] > b[1]:
        return 1
    elif a[1] == b[1]:
        if a[0] > b[0]:
            return 1
        elif a[0] < b[0]:
            return -1
        else:
            return 0
    else:
        return -1

N = int(sys.stdin.readline())

time_table = []

for i in range(N):
    cur_metting = list(map(int, sys.stdin.readline().split()))
    time_table.append(cur_metting)

time_table.sort(key = cmp_to_key(time_compare))

cur_meeting = [0, 0]

max_meeting_cnt = 0
for meeting in time_table:
    if meeting[0] >= cur_meeting[1]:
        cur_meeting = meeting
        max_meeting_cnt += 1

#print(time_table)
print(max_meeting_cnt)
