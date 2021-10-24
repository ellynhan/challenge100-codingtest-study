# 백준 15829번 Hashing
# 브론즈 2
L = int(input())
answer = 0
r = 1
for i, ss in enumerate(input()):
    s = ord(ss)-96
    answer += r*s%1234567891
    r *= 31
    r = r%1234567891

answer = answer%1234567891
print(answer)
