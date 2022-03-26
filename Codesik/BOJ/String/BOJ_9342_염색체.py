import re

T = int(input())

regex = re.compile('^[A-F]{0,1}A+F+C+[A-F]{0,1}$')

for _ in range(T):
    s = input()
    if regex.match(s):
        print("Infected!")
        continue
    print("Good")
