def isEqual(a, b):
    global answer
    if len(b) < 1:
        return
    if a == b:
        answer = 1
        return
    if b[-1] == 'A':
        isEqual(a, b[:-1])
    if b[0] == 'B':
        isEqual(a, b[1:][::-1])

s = input()
t = input()
answer = 0
isEqual(s, t)
print(answer)
