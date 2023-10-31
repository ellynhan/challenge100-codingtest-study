import sys
input = lambda: sys.stdin.readline().strip()
N = int(input())
pattern = input()

# 패턴을 별표를 기준으로 앞과 뒤로 나눈다.
start, end = pattern.split('*')

for _ in range(N):
    filename = input()
    # 파일 이름이 시작 부분으로 시작하고 끝 부분으로 끝나는지 확인한다.
    if filename.startswith(start) and filename.endswith(end) and len(filename) >= len(start) + len(end):
        print('DA')
    else:
        print('NE')