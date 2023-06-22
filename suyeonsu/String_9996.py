n = int(input())
s, e = input().split('*')
for _ in range(n):
    file = input()
    if file.startswith(s) and file[len(s):].endswith(e):
        print('DA')
    else:
        print('NE')
