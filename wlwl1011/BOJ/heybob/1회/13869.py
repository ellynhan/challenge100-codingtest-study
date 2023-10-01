import math

def calculate_area(S):
    N = len(S)
    S.sort()
    new_order = [S[-1]]  # 가장 큰 값을 중앙에

    for i in range(1, N):
        if i % 2 == 1:
            new_order.insert(0, S[-(i+1)])
        else:
            new_order.append(S[-(i+1)])

    area = 0.0
    angle = 2 * math.pi / N
    for i in range(N):
        x1 = new_order[i] * math.cos(i * angle)
        y1 = new_order[i] * math.sin(i * angle)
        x2 = new_order[(i+1) % N] * math.cos((i+1) * angle)
        y2 = new_order[(i+1) % N] * math.sin((i+1) * angle)

        area += (x1 * y2 - x2 * y1) / 2.0

    return abs(area)

N = int(input().strip())
S = list(map(int, input().split()))
print("{:.3f}".format(calculate_area(S)))
