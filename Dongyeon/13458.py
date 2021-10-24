place = int(input())
stu = input().split()
students = list(map(int, stu))

watch = input().split()
b = int(watch[0])
c = int(watch[1])
count = 0
for i, s in enumerate(students):
    if s <= b:
        count += 1
        continue
    else:
        s = s-b
        d = (s + c-1) // c +1
        count += d

print(count)
