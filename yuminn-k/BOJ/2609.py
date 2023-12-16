firstVal, secondVal = map(int,input().split())

# 최대공약수
# firstVal & secondVal의 최대 공약수는 secondVal & firstVal를 secondVal로 나눈 나머지의 최대 공약수
def gcd(firstVal, secondVal):
    while secondVal > 0:
        firstVal, secondVal = secondVal, firstVal % secondVal
    return firstVal

# 최소공배수 
# firstVal와 secondVal의 곱을 firstVal와 secondVal의 최대 공약수로 나눈 값
def lcm(firstVal, secondVal):
    return firstVal * secondVal // gcd(firstVal, secondVal)

print(gcd(firstVal, secondVal))
print(lcm(firstVal, secondVal))