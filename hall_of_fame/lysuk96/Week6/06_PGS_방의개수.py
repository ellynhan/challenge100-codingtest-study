from collections import defaultdict, deque
def solution(arrows):
    answer = 0
    move= [(0,1), (1,1), (1,0), (1,-1), (0,-1), (-1,-1), (-1,0), (-1,1)]
    now = (0,0)

    q = deque()
    q.append(now)
    for arrow in arrows:
        for _ in range(2):
            new = (now[0] + move[arrow][0], now[1]+move[arrow][1])
            q.append(new)
            now=new

    visit = defaultdict(int)
    visit_edge = defaultdict(int)

    now = q.popleft()
    visit[now] = 1

    while q:
        new = q.popleft()
        if visit[new] == 1:
            if visit_edge[now,new] == 0:
                answer+=1
        visit[new] = 1
        visit_edge[now, new] = 1
        visit_edge[new, now] = 1
        now = new
    # print(visit,'\n',visit_edge)

    return answer