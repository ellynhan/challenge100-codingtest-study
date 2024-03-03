
import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N = int(input())

arr = []
for _ in range(N):
    idx, level = map(int, input().split())
    arr.append([idx, level])

arr.sort(key=lambda x: x[0])

#가장 높은 기둥의 번호를 알아낸다. 
max_level = 0
max_idx = 0
for i in range(N):
    if arr[i][1] > max_level:
        max_level = arr[i][1]
        max_idx = i

#print(max_level, max_idx)

temp_idx = arr[0][0]
height = arr[0][1]

answer = 0
#최대 높이전까지 돌면서 다음 기둥이 현재보다 높으면 
#result에 현재의 면적을 계산해서 더해주고 높이를 다음 기둥으로 갱신한다.
for i in range(max_idx+1):
    idx, level = arr[i][0], arr[i][1]
    if level >= height:
        #print(i, idx, temp_idx, height)
        answer += (idx - temp_idx) * height 
        #print((idx - temp_idx) * height )
        height = level
        temp_idx = idx

answer += max_level



#뒤에서부터도 똑같이 진행한다. 
height = arr[N-1][1]
temp_idx = arr[N-1][0]

for i in range(N-1, max_idx-1,-1):
    idx, level = arr[i][0], arr[i][1]
    if level >= height:
        answer += (temp_idx - idx) * height 
        height = level
        temp_idx = idx



print(answer)