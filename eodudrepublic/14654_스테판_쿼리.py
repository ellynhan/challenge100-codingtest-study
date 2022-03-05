import sys

rounds = int(sys.stdin.readline())

a_team = list(map(int, sys.stdin.readline().split()))
b_team = list(map(int, sys.stdin.readline().split()))

a = "a"
b = "b"
d = "d"
N = "n"

def rsp(a, b) :
    if (a == 1 and b == 2) or (a == 2 and b == 3) or (a == 3 and b == 1) :
        return "b"
    elif (a == 2 and b == 1) or (a == 3 and b == 2) or (a == 1 and b == 3) :
        return "a"
    else :
        return "d"

ex_winner = N
win = 0
max_win = 0
for i in range(rounds) :
    winner = rsp(a_team[i], b_team[i])
    if winner == ex_winner :
        win += 1
    elif ex_winner == N :
        ex_winner = winner
        win = 1
    elif winner != ex_winner :
        if win > max_win :
            max_win = win
        if ex_winner == a :
            ex_winner = b
        else :
            ex_winner = a
        win = 1
if win > max_win :
    max_win = win

print(max_win)

# max_win = 0
# win = 0
# winner = -1

# for i in range(rounds) :
#     a = a_team[i]
#     b = b_team[i]
#     if (a == 1 and b == 2) or (a == 2 and b == 3) or (a == 3 and b == 1) :
#         if winner == -1 :
#             winner = 1
#         if winner == 1 :
#             win += 1
#         else:
#             if max_win < win:
#                 max_win = win
#             winner = 0
#             win = 1
#     elif (a == 2 and b == 1) or (a == 3 and b == 2) or (a == 1 and b == 3) :
#         if winner == -1 :
#             winner = 0
#         if winner == 0 :
#             win += 1
#         else:
#             if max_win < win :
#                 max_win = win
#             winner = 1
#             win = 1
#     else :
#         if max_win < win :
#             max_win = win
#         if winner == 0:
#             winner = 1
#         else:
#             winner = 0
#         win = 1

# if max_win < win:
#     max_win = win

# print(max_win)
