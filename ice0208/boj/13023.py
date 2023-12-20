import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())

    graphs = [[] for _ in range(N)]

    for _ in range(M):
        a, b = map(int, input().split())
        graphs[a].append(b)
        graphs[b].append(a)

    for start in range(N):
        stack = []
        stack.append((start, 1, {start}))

        while stack:
            cur, cnt, visit = stack.pop()
            if cnt == 5:
                print(1)
                sys.exit()
            for nxt in graphs[cur]:
                if nxt in visit:
                    continue

                stack.append((nxt, cnt + 1, visit | {nxt}))

    print(0)
