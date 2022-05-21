s = input()
slist = []

for _ in s:
    slist.append(s)
    s = s[1:]

for i in sorted(slist):
    print(i)
