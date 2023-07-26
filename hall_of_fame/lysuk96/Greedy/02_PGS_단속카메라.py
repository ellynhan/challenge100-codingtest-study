#단속카메라
#1트 : sort 안해서 틀림

def solution(routes):
    routes.sort()
    camera = [routes[0]]
    for route in routes:
        for j, cam in enumerate(camera):
            # print(route, cam)
            left = max(route[0], cam[0])
            right = min(route[1], cam[1])
            if left <= right:
                camera[j] = [left, right]
                break
            if j == len(camera)-1:
                camera.append(route)

    return len(camera)

print(solution([[0,2],[2,3],[3,4],[4,6]]))

#다른 사람 예술 풀이
# def solution(routes):
#     routes = sorted(routes, key=lambda x: x[1])
#     last_camera = -30000

#     answer = 0

#     for route in routes:
#         if last_camera < route[0]:
#             answer += 1
#             last_camera = route[1]

#     return answer
