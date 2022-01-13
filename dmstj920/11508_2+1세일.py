num = int(input())
price = []
remain = num % 3
sum = 0

for i in range(num):
    price.append(int(input()))

price.sort()
for i in range(num):
    if remain != 0 :
        if i < remain:
            sum += price[i]
            continue

    if (i % 3) != remain:
        sum += price[i]

print(sum)
