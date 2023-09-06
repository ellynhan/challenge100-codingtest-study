import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

#바로 옆에 다른 색깔의 볼이 있으면 그 볼을 모두 뛰어 넘어 옮길 수 있다

#옮길 수 있는 볼의 색깔은 한 가지이다. 즉, 빨간색 볼을 처음에 옮겼으면 다음에도 빨간색 볼만 옮길 수 있다

def init(color, ball):
    for _ in range(len(ball)):
        c = ball.pop()
        if c != color:
            ball.append(c)
            break
    return ball    

def move(color, ball):
    ball = init(color, ball)
    return ball.count(color)


N = int(input())
ball = list(input())

print(min(move('R',ball[:]),move('R',ball[::-1]),move('B',ball[:]),move('R',ball[::-1])))