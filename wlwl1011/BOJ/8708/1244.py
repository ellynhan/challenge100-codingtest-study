import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

#남학생은 스위치 번호가 자기가 받은 수의 배수이면,
# 그 스위치의 상태를 바꾼다.

#여학생은 자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간을 찾아서, 
# 그 구간에 속한 스위치의 상태를 모두 바꾼다. 


#첫째 줄에는 스위치 개수
switch_N = int(input())

#각 스위치의 상태
arr = [0] + list(map(int,input().split()))

#학생수
student_N = int(input())
student = []

for i in range(student_N):
    sex, number = map(int, input().split())
    #student.append(list(sex, number))
    if sex == 1:
        for j in range(1, switch_N+1):
            if j % number == 0: # 스위치 번호가 자기가 받은 수의 배수이면
                # 그 스위치의 상태를 바꾼다.
                if arr[j]:
                    arr[j] = 0
                else:
                    arr[j] = 1     
    else: #여학생이면     
        start = number
        end = number
        for j in range(1, switch_N+1):
            
            if number+j <= switch_N and number-j > 0:
                if arr[number+j] == arr[number-j] :
                    start = number-j
                    end = number+j
                else:
                    break  
              
        #print(start,end)       
        for j in range(start, end+1):
            if arr[j]:
                arr[j] = 0
            else:
                arr[j] = 1    
    #print(*arr[1:])                     


for i in range(1, switch_N+1):
    print(arr[i],end=' ')
    if i % 20 == 0:
        print()