d = ['N', 'E', 'S', 'W']
i = 0
for _ in range(10):
    t = int(input())
    if t == 1:
        i += 1
        if i > 3:
            i = 0
    elif t == 2:
        i += 2 if i+2 <= 3 else -2
    else:
        i -= 1
        if i < 0:
            i = 3
print(d[i])
