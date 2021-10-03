A, B = map(int,input().split())
answer = 1
while True:
    if B % 2 == 0:
        B = B / 2
    else:
        B -= 1
        B /= 10
    answer += 1
    if B <= A:
        break

if B < A:
    print(-1)
else:
    print(answer)