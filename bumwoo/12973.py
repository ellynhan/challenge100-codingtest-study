def solution(s):
    stack = []
    stack.append(s[0])
    for i in range(1, len(s)):
        if stack and s[i] == stack[-1]:
            stack.pop()
        else:
            stack.append(s[i])

    if stack:
        return 0
    else:
        return 1
