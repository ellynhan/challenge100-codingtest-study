import string

def is_prime(x):
    import math
    if x<2: return 0
    for i in range(2,int(math.sqrt(x))+1):
        if x%i==0: return 1
    return 1

tmp = string.digits + string.ascii_lowercase
def convert(num, base) :
    q, r = divmod(num, base)
    print(q, r)
    if q == 0 :
        return tmp[r] 
    else :
        return convert(q, base) + tmp[r]
    
def solution(n, k):
    answer = 0

    convert_num = str(convert(n, k))
    prev_cursor = 0
    for cursor, num in enumerate(convert_num):
        if num == '0':
            if prev_cursor != cursor:
                answer += is_prime(int(convert_num[prev_cursor : cursor]))
            prev_cursor = cursor + 1
    if prev_cursor != len(convert_num):
        # print(int(convert_num[prev_cursor : len(convert_num)]))
        answer += is_prime(int(convert_num[prev_cursor : len(convert_num)]))
        
    return answer