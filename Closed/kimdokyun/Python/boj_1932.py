N = int(input())
tri = [[int(input())]]
for i in range(1, N):
    nums = list(map(int, input().split()))
    for j in range(len(nums)):
        back = 0
        if j-1 >= 0:
            back = max(back, tri[i-1][j-1])
        if j < len(tri[i-1]):
            back = max(back, tri[i-1][j])
        nums[j] += back
    tri.append(nums)
print(max(tri[N-1]))
