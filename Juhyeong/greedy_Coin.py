n = 1260
count = 0

coin_types = [500,100,50,10]

for coin in coin_types:
    count += n//coin
    n %= coin

print(count)
