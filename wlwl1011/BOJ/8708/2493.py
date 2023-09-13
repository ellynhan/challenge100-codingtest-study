# import sys, os, io, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
# atexit.register(lambda: os.write(1, stdout.getvalue()))


#처음에 시간 초과를 고려해 이진 탐색을 이용해서 풀이했으나, 이진 탐색을 쓰더라도 시간 초과 발생
#다른 풀이 필요 -> stack

N = int(input())
arr = list(map(int, input().split()))
stack = []
answer = []


for i in range(N):
    while stack:
        if stack[-1][1] > arr[i]: #수신 가능
            answer.append(stack[-1][0] + 1)
            break
        else:
            stack.pop()
    if not stack: #수신할 탑 없음
        answer.append(0)
    stack.append([i, arr[i]]) #인덱스 값
print(*answer)