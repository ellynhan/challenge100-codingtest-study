def addFish():
    m = bowls[0][0]
    for row in bowls:
        for x in row:
            if x < m: m = x
    for row in bowls:
        for i in range(len(row)):
            if row[i] == m: row[i] += 1

def cw(arr):
    rotated = []
    for row in list(map(list, zip(*arr[::-1]))):
        rotated.append(row)
    return rotated

def roll():
    global bowls
    a, b = [bowls[0]], bowls[1:]
    k = 0
    while len(a[0]) <= len(b):
        a = cw(a)
        for i in range(len(a)):
            b[i] += a[i]
        k += 1
        a, b = b[:k//2+1], b[k//2+1:]
    bowls = a + b

def moveFish():
    global bowls
    di = [0, -1, 0, 1]
    dj = [-1, 0, 1, 0]
    visited = [[0] * len(bowls[i]) for i in range(len(bowls))]
    moved = [row[:] for row in bowls]
    for i in range(len(bowls)):
        for j in range(len(bowls[i])):
            if not visited[i][j]:
                visited[i][j] = 1
                for nxt in zip(di, dj):
                    ni, nj = i+nxt[0], j+nxt[1]
                    if 0 <= ni < len(bowls) and 0 <= nj < len(bowls[ni]):
                        d = abs(bowls[ni][nj] - bowls[i][j]) // 5
                        if d > 0:
                            if bowls[ni][nj] > bowls[i][j] and moved[ni][nj]:
                                moved[i][j] += d
                            elif bowls[ni][nj] < bowls[i][j] and moved[i][j]:
                                moved[i][j] -= d
    bowls = moved

def flatten():
    global bowls
    flattened = []
    for row in bowls:
        for x in row:
            flattened.append([x])
    bowls = flattened

def fold():
    global bowls
    for _ in range(2):
        a, b = bowls[:len(bowls)//2], bowls[len(bowls)//2:]
        a = cw(cw(a))
        for i in range(len(a)):
            b[i] += a[i]
        bowls = b

def gap(arr):
    M, m = arr[0][0], arr[0][0]
    for a in arr:
        for x in a:
            if x > M: M = x
            if x < m: m = x
    return M - m

n, k = map(int, input().split())
bowls = [[x] for x in list(map(int, input().split()))]
answer = 0
while gap(bowls) > k:
    answer += 1
    addFish()
    roll()
    moveFish()
    flatten()
    fold()
    moveFish()
    flatten()
print(answer)

"""
문제 읽으면서 바로바로 메인함수에 모듈화해서 만들어놓고 하나하나 구현하기
+) 한번에 싹 구현해서 테케 돌리려 하지말고, 하나 구현하고 원하는대로 동작하는지 출력해서 확인해보고 또 하나 구현하고 또 확인하고 를 반복하기
(인덱스가 헷갈리는 등) 규칙을 찾기 어려울 때는 손으로 직접 5-6단계 정도 그려보고 규칙 찾아내기

2차원 배열을 복사할 때는 반드시 for문을 사용해서 1차원 배열부터 복사해야 깊은 복사가 진행됨.
배열을 회전할 때 매핑해서 리스트 형태로 활용할 수 있게 하기.(그렇지 않으면 튜플로 저장됨)
"""
