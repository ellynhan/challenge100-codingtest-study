num = int(input())
total = 0

time = [int(x) for x in input().split()]

time.sort()
for i in range(num):
    total += time[i] * (num-i)

print(total)
