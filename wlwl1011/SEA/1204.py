for _ in range(int(input())):
    ans = 0
    test_case = int(input())
    arr = [0] * 1001
    for index in map(int, input().split()):
        arr[index] += 1
    if arr.count(max(arr)) == 1:    
        ans = arr.index(max(arr))
    else:
        ans = max(list(filter(lambda x : arr[x] == max(arr), range(len(arr)))))
    print('#', test_case, ' ', ans,sep='')