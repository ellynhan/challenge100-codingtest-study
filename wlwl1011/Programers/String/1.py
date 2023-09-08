from itertools import combinations

def calculation(eq1, eq2):
    x1, y1, c1 = eq1 # 직선1
    x2, y2, c2 = eq2 # 직선2
    
    # 기울기가 깉아 해가 없는 경우
    if x1*y2 == y1*x2: 
        return
    
    # 두 직선의 해
    x = (y1*c2-c1*y2)/(x1*y2-y1*x2)
    y = (c1*x2-x1*c2)/(x1*y2-y1*x2)
    
    # 두 직선의 해 x, y가 모두 정수라면 반환
    if x == int(x) and y == int(y):
        return [int(x), int(y)]

def solution(lines):
    points = []
    # 모든 선들의 교점 확인
    for eq1, eq2 in combinations(lines,2):
        point = calculation(eq1,eq2)
        if point: points.append(point)
        
    # 그림의 시작점과 마지막점 찾기
    w1, w2 = min(points, key = lambda x : x[0])[0], max(points, key = lambda x : x[0])[0] + 1
    h1, h2 = min(points, key = lambda x : x[1])[1], max(points, key = lambda x : x[1])[1] + 1
    
    # 별을 포함하는 최소한의 크기 배열 생성
    answer = [['.'] * (w2 - w1) for _ in range((h2 - h1))]

    # 그림의 시작점을 기준으로 교점 위치 "*" 변환
    for x, y in points:
        answer[y-h1][x-w1] = '*'
    
    answer.reverse()
    
    return [''.join(a) for a in answer]