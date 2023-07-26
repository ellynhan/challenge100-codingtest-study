#https://www.acmicpc.net/problem/2457
#1트 : day 직접 1씩 늘려가며 check (sort만으론 개화 가장 긴 꽃을 찾을 수 없었음)
#2트 : now, next 도입해서 성공
# 어떻게 두방법중 선택해야할까?

from collections import deque
month = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for i in range(1, 13):
    month[i] += month[i-1]

flowers = []

N = int(input())
for _ in range(N):
    sm, sd, em, ed = map(int, input().split())

    s_days , e_days = month[sm-1], month[em-1]
    s_days += sd
    e_days += ed
    flowers.append((s_days, e_days))

flowers.sort(key = lambda x: x[0])
# print(month)
# print(flowers)

answer = 0
now = month[2]+1
next = -1

for start, end in flowers:
    if next > month[11]:
        break

    # print(answer, now, next)
    if start <= now < end:
        if next < end:
            next = end
    else:
        if start <= next < end:
            answer+=1
            now = next
            next = end
        elif end <= next:
            continue
        else:
            break
if next <= month[11]:
    answer = 0
else:
    answer+=1

print(answer)
        
# 1트 실패한 코드
# for day in range(month[2]+1, month[11]+1):
#     if (nowf != -1) and (nowf[0] <= day < nowf[1]):
#         # print(day)
#         continue
#     else:
#         while flowers and (flowers[0][0] > day or flowers[0][1] <= day):
#             flowers.popleft()
#         # print(flowers)
#         if flowers :
#             # while len(flowers)>=2 and ((flowers[1][0] < day and flowers[1][1]-day >0)\
#             #     or flowers[1]:
#             #     flowers.popleft()
#             nowf = flowers.popleft()
#             # print(day, nowf, flowers)
#             answer+=1
#         else:
#             # print(day)
#             answer = 0
#             break
# print(answer)