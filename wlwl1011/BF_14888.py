import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s:stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

def check(i,j,k):

    if k == 0:
        return (i+j)
    elif k == 1:
        return (i-j)
    elif k == 2:
        return (i*j)
    elif k == 3:
        #음수를 양수로 나눌 때는 C++14의 기준을 따른다.
        if i<0:
            return (-i//j)*-1
        else:    
            return (i//j)            

def solve(depth,number):

    if depth == N:
        answer.append(number)
        return    

    if depth == 0:
        solve(depth+1, arr[0])
    
    for j in range(4): #덧셈, 뺄셈, 곱셈, 나눗셈
        if operand[j] == 0:
            continue
        #이 부분은 주석처리하니까 통과합니다 ...?
        # if j == 3 and number == 0:
        #     continue
        new_value = check(number, arr[depth], j)    
        operand[j] -= 1
        solve(depth+1, new_value)
        operand[j] += 1
         
                

answer = []

#수의 개수
N = int(input())
arr = list(map(int, input().split()))
#덧셈 뺄셈 곱셈 나눗셈
operand = list(map(int, input().split()))
solve(0,0)


print(max(answer))
print(min(answer))