# 백준 1011번 Fly me to the Alpha Centauri
# 골드 5

N = int(input())


def pyramid(n):
    answer = 0
    if n ==0:
        return 0
    for i in range(n-1):
        answer += 2*(i+1)
    answer += n
    return answer

def isnotzero(n):
    if n == 0:
        return 0
    else:
        return 1

for _ in range(N):
    x, y = map(int, input().split())
    y = y - x

    mx = int(pow(y, 0.5))
    tmp = y - pow(mx, 2)
    if tmp >= mx:
        print(2*mx+ isnotzero(tmp-mx))
    else:
        print(2*mx -1 + isnotzero(tmp))
