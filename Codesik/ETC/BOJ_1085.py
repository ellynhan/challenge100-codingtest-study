"""
문제:
    한수는 지금 (x, y)에 있다. 직사각형은 각 변이 좌표축에 평행하고,
    왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다.
    직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
제한:
    시간 제한:2초, 메모리제한: 128MB
입력:
    첫째 줄에 x, y, w, h가 주어진다.
출력:
    첫째 줄에 문제의 정답을 출력한다.
시작:
    9.4 00:15
소요시간:
    12분
"""

def solution(x, y, w, h):
    answer = []
    if x < w / 2:
        answer.append(x)
    else:
        answer.append(w-x)

    if y < h / 2:
        answer.append(y)
    else:
        answer.append(h-y)
    return min(answer)

x, y, w, h = map(int, input().split())
print(solution(x, y, w, h))