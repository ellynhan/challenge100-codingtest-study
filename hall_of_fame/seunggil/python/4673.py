from collections import OrderedDict

result = OrderedDict()


for i in range(10000):
    t = i + sum(map(int, str(i)))
    result[t] = None

for i in range(1,10001):
    if i not in result:
        print(i)
