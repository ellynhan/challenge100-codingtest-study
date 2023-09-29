T = int(input())
for test_case in range(T):
    ans = 0
    arr = list(map(int, input().split()))
    for i in arr:
        if i % 2:
            ans += i
    print('#',test_case+1,' ',ans,sep='')