hour, min = map(int, input().split())

if min >= 45 :
    min -= 45
else :
    min = 45 - min
    min = 60 - min
    if hour == 0 :
        hour = 23
    else :
        hour -= 1

print(f"{hour} {min}")
