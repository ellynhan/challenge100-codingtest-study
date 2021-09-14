# 몇 초만에 시작점으로 돌아오는가? 를 고려하면 성능이 더 좋아질까? -> 그런듯!
# 거꾸로 돌기를 추가하면 성능이 더 좋아질까? 근데 구현을 제대로 못하겠음..
# dp 문제일까?! 일단 안 쓰고 풀어봄

import sys


def get_distance(p):
    distance_list = []
    for i in range(len(p)):
        distance_list.append(abs(p[i-1][0] - p[i][0] + p[i-1][1] - p[i][1]))
    distance_list.append(distance_list.pop(0))
    return distance_list, sum(distance_list)


def get_location(dists, pts, sec):
    if sec == 0:
        return points[0]

    for i in range(len(dists)):
        if sec > dists[i]:
            sec -= dists[i]
        elif sec == dists[i]:
            return pts[i+1]
        else:
            i2 = i+1
            if i == len(dists)-1:
                i2 = 0

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


points = []
for _ in range(int(sys.stdin.readline())):
    x, y = map(int, sys.stdin.readline().split())
    points.append([x, y])
times = list(map(int, sys.stdin.readline().split()))

distances, perimeter = get_distance(points)

for second in times:
    print(*get_location(distances, points, second % perimeter))
