import sys
input = sys.stdin.readline

_ = input()
nums = list(map(int, input().split()))

# Binary_search method

def binary_search(lis_arr, num): #

    low = -1 # 접근 X
    high = len(lis_arr) # 접근 X

    # 결정 문제
    # [1 3 5] 에서 2가 들어오면 [2 3 5]가 되어야 함

    # num은 mid보다 큰가? -> TF문제에서 가장 작은 F (high)
    # 왜 초과인가? -> 같은 숫자가 들어올 수 있기 때문
    
    while low +1 < high:
        #print(lis_arr)
        mid = (low + high)//2 

        if num > lis_arr[mid]: # TTF므로 왼쪽 탐색 X
            low = mid
        else:
            high = mid

    return high

lis_arr = [-1000000001]
lis_total = [(-1000000001,0)] # number, index

nums = nums[::-1] # stack처럼 쓰기 위해

while nums:
    num = nums.pop()

    if num > lis_arr[-1]:
        lis_total.append((num, len(lis_arr)))
        lis_arr.append(num)

    else:
        idx = binary_search(lis_arr, num)
        lis_arr[idx] = num
        lis_total.append((num, idx))

lis_length = len(lis_arr)-1
lis = []

#print(lis_total)

while lis_total and lis_length:
    num, idx = lis_total.pop()
    if idx == lis_length:
        lis.append(num)
        lis_length -= 1

print(len(lis))
print(*lis[::-1])