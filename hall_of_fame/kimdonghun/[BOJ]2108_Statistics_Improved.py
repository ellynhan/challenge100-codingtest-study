import sys
from collections import Counter

N = int(sys.stdin.readline())

s_list = []
m_list = {}

for i in range(N):
    cur_num = int(sys.stdin.readline())
    s_list.append(cur_num)
    
cnt = 0

s_list.sort()

for i in s_list:
    try:
        m_list[i] += 1
    except:
        m_list[i] = 1

#print(m_list)

m_sort = sorted(m_list.items(), key=lambda x: x[1])
#print(m_sort)

most_cnt = 0
most_val = s_list[0]
for i in range(len(m_sort)):
    if most_cnt < m_sort[i][1]:
        most_cnt = m_sort[i][1]
        
        if i+1 < len(m_sort) and m_sort[i+1][1] == m_sort[i][1]:
            most_val = m_sort[i+1][0]
        else:
            most_val = m_sort[i][0]

arithmetic_mean = sum(s_list) / N

#print(s_list)

print(round(arithmetic_mean))
print(s_list[N//2])

'''
cnt = Counter(s_list).most_common(2) 
if len(s_list) > 1: 
    if cnt[0][1] == cnt[1][1]: 
        print(cnt[1][0]) 
    else: print(cnt[0][0]) 
else: print(cnt[0][0])
'''
print(most_val)

print(max(s_list) - min(s_list))
