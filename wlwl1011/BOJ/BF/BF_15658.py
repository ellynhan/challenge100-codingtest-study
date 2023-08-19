import sys, os, io, atexit
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

def check(i, j, k):
    if k == 0:
        return i + j
    elif k == 1:
        return i - j
    elif k == 2:
        return i * j
    else:
        if i < 0 :
            return (-i//j)*-1
        else:
            return i//j

def solve(depth, number):
    if depth == N:
        answer.append(number)
        return
    if depth == 0:
        #그 다음 계산하러 가자
        solve(depth+1, arr[0])
    else:
        for index in range(4): #덧셈 뺄셈 곱셈 나눗셈
            if operand[index] != 0:
                new_number = check(number, arr[depth], index)
                operand[index] -= 1
                solve(depth+1, new_number)
                operand[index] += 1
               


answer = []
N = int(input())
arr = list(map(int, input().split()))
operand = list(map(int, input().split()))
solve(0,0)
print(max(answer))
print(min(answer))