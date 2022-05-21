def solution(sentence):
    stack = []
    sentence = list(sentence)
    stack.append(sentence.pop(0))

    for s in sentence:
        if not stack:
            stack.append(s)
            continue

        if stack[-1] == s:
            stack.pop()
            continue

        if stack[-1] != s:
            stack.append(s)
            continue

    if not stack:
        return 1

    return 0