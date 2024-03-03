n = int(input())
oasis = []
for _ in range(n):
    oasis.append(int(input()))

answer = 0
stack = []
for o in oasis:
    while stack and stack[-1][0] < o:
        answer += stack.pop()[1]

    if not stack:
        stack.append((o, 1))
        continue

    # 키가 같을 때
    if stack[-1][0] == o:
        cnt = stack.pop()[1]
        answer += cnt

        if stack:
            answer += 1
        stack.append((o, cnt + 1))

    else:
        stack.append((o, 1))
        answer += 1

print(answer)





