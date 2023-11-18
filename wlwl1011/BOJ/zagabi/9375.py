import sys
input = lambda : sys.stdin.readline().strip()

T = int(input())

for _ in range(T):
    dictionary = {}
    N = int(input())
    for _ in range(N):
        name, kind = input().split()
        if kind not in dictionary:
            dictionary[kind] = 1  # 의상의 종류를 처음 보면 1로 시작 (해당 종류의 의상을 입는 경우)
        else:
            dictionary[kind] += 1  # 이미 있는 종류면 +1 (추가 의상을 입는 경우)

    answer = 1
    for key in dictionary:
        answer *= (dictionary[key] + 1)  # 각 종류별로 의상을 입거나 안 입는 경우의 수 계산

    answer -= 1  # 모든 종류를 안 입는 경우 제외
    print(answer)
