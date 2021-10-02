# 백준 1014번 어린왕자
# 실버 3

T = int(input())

for _ in range(T):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    l=[]
    for _ in range(n):
        l.append(list(map(int, input().split())))

    answer = 0

    for i in range(n):
        a, b, c = l[i]
        s_in = ((x1-a)**2 + (y1-b)**2 < c**2)
        e_in = ((x2-a)**2 + (y2-b)**2 < c**2)
        if s_in and not e_in:
            answer += 1
        elif e_in and not s_in:
            answer += 1
        else:
            continue
    print(answer)
