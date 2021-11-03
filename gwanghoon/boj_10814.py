import sys

if __name__ == "__main__":
    testCase = int(sys.stdin.readline())
    members = []

    for i in range(testCase):
        age, name = map(str, sys.stdin.readline()[:-1].split())
        age = int(age)
        members.append((age, name))
    members.sort(key = lambda x : x[0])

    for i in members:
        print(i[0], i[1])

# 17분 / 실버5 / input()쓰니까 시간초과
