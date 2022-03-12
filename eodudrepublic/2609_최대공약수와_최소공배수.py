import sys

def get_small_number(num) :
    small_number_list = []
    k = 2
    while num != 1 :
        if num % k == 0 :
            small_number_list.append(k)
            num /= k
        else :
            k += 1
    return small_number_list
    
a, b = map(int, sys.stdin.readline().split())

a_small_num = get_small_number(a)
b_small_num = get_small_number(b)

a_b = a_small_num.copy()
ab = []

for i in b_small_num :
    if i not in a_small_num :
        a_b.append(i)
    else :
        a_small_num.remove(i)
        ab.append(i)

num1 = 1
for i in ab :
    num1 *= i
print(num1)

num2 = 1
for i in a_b :
    num2 *= i
print(num2)
