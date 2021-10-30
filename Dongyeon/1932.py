#백준 1932번 정수 삼각형

def find_three(tri, i, j, d):
    if (i, j) in d.keys():
        return d[(i, j)]
    else :
        d[(i, j)] = tri[i][j] + max(find_three(tri, i+1, j, d), find_three(tri, i+1, j+1, d))
        return d[(i, j)]


n = int(input())
triangle = []
for _ in range(n):
    triangle.append(list(map(int, input().split())))
d = {}
for i, k in enumerate(triangle[-1]):
    d[(n-1, i)] = k


print(find_three(triangle, 0, 0, d))
