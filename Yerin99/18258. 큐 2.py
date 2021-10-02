import sys
dic = {}
f = -1
b = -1
where = 0
for i in range(int(input())):
    a = sys.stdin.readline().split()
    if a[0] == "push":
        if where == 0:
            f = 0
        dic[where] = a[1]
        b = where
        where += 1
    elif a[0] == "front":
        print(-1 if dic.get(f) is None else dic[f])
    elif a[0] == "back":
        print(-1 if dic.get(f) is None else dic[b])
    elif a[0] == "pop":
        if dic.get(f) is None:
            print(-1)
        else:
            print(dic.pop(f))
            f += 1
    elif a[0] == "size":
        print(len(dic))
    elif a[0] == "empty":
        print(0 if len(dic) > 0 else 1)
