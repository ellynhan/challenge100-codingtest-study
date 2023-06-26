n = input()
if len(n) == 1: n = '0' + n

answer = 0
num = n
while True:
    num = num[-1] + str(int(num[0]) + int(num[-1]))[-1]
    answer += 1
    if num == n: break
print(answer)
