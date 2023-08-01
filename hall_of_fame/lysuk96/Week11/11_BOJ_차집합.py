NA, NB = map(int, input().split(" "))
A = set(map(int, input().split(" ")))
B = set(map(int, input().split(" ")))

cha = (A | B) - B
cha = sorted(list(cha))
if len(cha)==0:
    print(0)
else:
    print(len(cha))
    print(*cha)