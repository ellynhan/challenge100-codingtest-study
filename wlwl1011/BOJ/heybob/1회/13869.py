import math

def calculate_area(S):
    N = len(S)
    S.sort()
    new_order = [0 for _ in range(N)]  # 가장 큰 값을 중앙에
    start = 0
    end = N-1
    for i in range( N):
        if i % 2 == 0:
            new_order[start] = S[i]
            start +=1
        else:
            new_order[end] = S[i]
            end -= 1
    #print(new_order)
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
