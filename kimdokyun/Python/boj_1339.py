alpaDic = {chr(i) : 0 for i in range(ord('A'), ord('Z')+1) }

N = int(input())
for _ in range(N):
    word = input()[::-1]
    digit = 1
    for alpa in word:
        alpaDic[alpa] += digit
        digit *= 10

result = 0
value = 9
for alpaV in sorted(alpaDic.values(),reverse=True):
    if alpaV == 0 : break
    result += alpaV * value
    value -= 1

print(result)
