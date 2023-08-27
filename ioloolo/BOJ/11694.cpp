import sys

N = int(input())
input_list = list(map(int, input().split()))

flag = False
num = 0

for i in range(N):
    if input_list[i] != 1:
        flag = True
    else:
        num += 1

if not flag:
    print("cubelover" if num % 2 == 1 else "koosaga")
    exit(0)

result = 0
for i in range(N):
    result ^= input_list[i]

if num != 0:
    if num % 2 == 1 and result != 0:
        print("koosaga")
    elif num % 2 == 1 and result == 0:
        print("cubelover")
    elif num % 2 == 0:
        for i in range(N):
            if input_list[i] != 1:
                input_list[i] = 1
                break

        result = 0
        for i in range(N):
            result ^= input_list[i]

        if result != 0:
            print("koosaga")
        else:
            print("cubelover")
else:
    print("koosaga" if result != 0 else "cubelover")

