#백준 1018번 체스판 다시 칠하기
#실버 5

def make_wb(l):
    color = ["W", "B"]
    tmp = 0
    for i in range(len(l)):
        cnt = i%2
        for j in range(len(l[0])):
            if l[i][j] == color[cnt]:
                pass
            else:
                tmp += 1
            cnt = 1 - cnt
    return tmp

def make_bw(l):
    color = ["B", "W"]
    tmp = 0
    for i in range(len(l)):
        cnt = i%2
        for j in range(len(l[0])):
            if l[i][j] == color[cnt]:
                pass
            else:
                tmp += 1
            cnt = 1 - cnt
    return tmp

N, M = map(int, input().split())
l = []
for i in range(N):
    l.append(list(input()))

best = N*M
for i in range(N-7):
    for j in range(M-7):
        chess = [l[i+k][j:j+8] for k in range(8)]
        new_min = min(make_wb(chess), make_bw(chess))
        if best > new_min:
            best = new_min

print(best)

