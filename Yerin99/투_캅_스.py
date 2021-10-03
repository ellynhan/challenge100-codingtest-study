import sys


def get_distance(p):
    distance_list = []
    for i in range(len(p)):
        distance_list.append(abs(p[i-1][0] - p[i][0] + p[i-1][1] - p[i][1]))
    distance_list.append(distance_list.pop(0))
    return distance_list


def get_location(dists, pts, sec):
    for i in range(len(dists)):
        if sec > dists[i]:
            sec -= dists[i]
        elif sec == dists[i]:
            return pts[i+1]
        else:
            i2 = i+1
            if pts[i][0] == pts[i2][0]:
                if pts[i][1] < pts[i2][1]:
                    return [pts[i][0], pts[i][1] + sec]
                else:
                    return [pts[i][0], pts[i][1] - sec]
            else:
                if pts[i][0] < pts[i2][0]:
                    return [pts[i][0] + sec, pts[i][1]]
                else:
                    return [pts[i][0] - sec, pts[i][1]]


input_ = sys.stdin.readline
points = []

k = int(input_())
for _ in range(k):
    x, y = map(int, input_().split())
    points.append([x, y])
times = int(input_())

distances = get_distance(points)

distances_a, distances_b = distances[:k//2-1], distances[k//2-1:]
dist_a, dist_b = sum(distances_a), sum(distances_b)

c1, c2 = points[0], points[k//2-1]
flag = True

while True:
    if flag:
        if times >= dist_a:
            times -= dist_a
        else:
            break
    else:
        if times >= dist_b:
            times -= dist_b
        else:
            break

    flag = not flag

if times != 0:
    if flag:
        if times >= dist_a / 2:
            times = dist_a - times
        points_a = points[:k//2]
        c1 = get_location(distances_a, points_a, times)
        c2 = get_location(distances_a[::-1], points_a[::-1], times)
    else:
        if times >= dist_b // 2:
            times = dist_b - times
        points_b = points[k//2-1:] + [points[0]]
        c1 = get_location(distances_b[::-1], points_b[::-1], times)
        c2 = get_location(distances_b, points_b, times)

print(*c1)
print(*c2)
