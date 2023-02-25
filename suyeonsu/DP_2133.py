n = int(input())
tile = [0 for _ in range(n+1)]
tile[0] = 1
for i in range(2, n+1, 2):
    tile[i] = tile[i-2] * 3
    for k in range(0, i-2, 2):
        tile[i] += tile[k] * 2
print(tile[n])
