import sys

N = int(sys.stdin.readline())
S = 1
i = 1

while 1 :
    S += i

    if S > N :
        diff = S - N

        if i % 2 == 0 :
            numerator  = i+1 - diff
            denominator = diff
        else :
            denominator  = i+1 - diff
            numerator = diff

        break

    i += 1

print(str(numerator) + '/' + str(denominator))        