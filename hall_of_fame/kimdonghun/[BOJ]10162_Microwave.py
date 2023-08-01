import sys

T = int(sys.stdin.readline())
button_list = [300, 60, 10]
ans_list = []

for button in button_list:
    ans_list.append(T // button)
    T %= button

if T > 0:
    print(-1)
else:
    for ans in ans_list:
        print(ans, end=" ")
