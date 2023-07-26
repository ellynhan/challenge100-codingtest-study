n = int(input())

time_list = list(map(int, input().split()))

time_list.sort()

time = 0
sum = 0
for i in time_list:
    sum += i
    time += sum
    
print(time)