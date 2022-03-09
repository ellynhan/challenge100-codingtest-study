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

N = int(sys.stdin.readline())
list_N = get_small_number(N)
for i in list_N :
    print(i)
