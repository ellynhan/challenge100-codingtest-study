import sys
input = sys.stdin.readline

n, p = map(int, input().split())
pressed = {i:[] for i in range(1, 7)}
answer = 0
for _ in range(n):
    a, b = map(int, input().split())
    if pressed[a]:
        while pressed[a] and pressed[a][-1] > b:
            pressed[a].pop()
            answer += 1
        if not pressed[a] or pressed[a][-1] < b:
            pressed[a].append(b)
            answer += 1
    else:
        pressed[a].append(b)
        answer += 1
print(answer)
