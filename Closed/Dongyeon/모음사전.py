word = input()
d = {'A':1,
     'E': 2,
     'I': 3,
     'O': 4,
     'U': 5}

tmp = [d[w] for w in word]
for _ in range(5-len(word)):
    tmp.append(0)

answer = len(word)

a, b, c, d, e = tmp

answer += 781*max(0, a-1)
answer += 156 * max(0, b-1)
answer += 31*max(0, c-1)
answer += 6*max(0, d-1)
answer += max(0, e-1)
print(answer)
