"""
문제:
    지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다.
    지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.
    체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다.
    따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
    보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다.
    지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.
제한:
    시간 제한:2초, 메모리제한: 128MB
입력:
    첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
    둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.
출력:
    첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.로
시작:
    오후 11:32
"""


def solution(N: int, M: int, board: list) -> list:
    answer = []

    for col in range(N-7):
        for row in range(M-7):
            start_with_W = 0
            start_with_B = 0
            # 자른 정사각형 내에서 칠해야하는 개수를 구한다.
            for i in range(col,col+8):
                for j in range(row, row+8):
                    # 짝수 인덱스 일 때
                    # (0,0)에서 만약 B로 시작했으면 모든 짝수 인덱스는 같은 색깔이여야 한다.
                    if (i+j) % 2 == 0:
                        if board[i][j] != 'B':
                            start_with_B += 1
                        if board[i][j] != 'W':
                            start_with_W += 1
                    # 홀수 인덱스 일 때
                    # (0,0)에서 만약 B로 시작했으면 모든 홀수 인덱스는 다른 색깔이여야 한다.
                    else:
                        if board[i][j] != 'B':
                            start_with_W += 1
                        if board[i][j] != 'W':
                            start_with_B += 1
            answer.append(start_with_W)
            answer.append(start_with_B)

    return answer

# N이 세로, M이 가로
N, M = map(int, input().split())

board = []

for _ in range(N):
    board.append(input())

print(min(solution(N, M, board)))

