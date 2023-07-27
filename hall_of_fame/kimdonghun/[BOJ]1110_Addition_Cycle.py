import sys

N = int(sys.stdin.readline())
A = N // 10
B = N % 10
cycle_Num = 0

while 1:
    temp = B
    B = (A+B) % 10
    A = temp

    cycle_Num += 1

    if N == A * 10 + B:
        print(cycle_Num)
        break

'''
inputNum = int(sys.stdin.readline())
N = list(map(int, str(inputNum)))

if len(N) == 1 :
    N.insert(0, 0)

sum = list(map(int, str(int(N[0]) + int(N[1]))))

if len(sum) == 1 :
    sum.insert(0, 0)

new_Num = [N[1], sum[1]]
cycle_Num = 1


while N != new_Num :
    if len(new_Num) == 1 :
        new_Num.insert(0, 0)

    sum = list(map(int, str(int(new_Num[0]) + int(new_Num[1]))))

    if len(sum) == 1 :
        sum.insert(0, 0)
        
    new_Num = [new_Num[1] , sum[1]]

    
    print(new_Num)
    print(N)
    print("=======")
    

    cycle_Num += 1
    
    print(cycle_Num)

'''


