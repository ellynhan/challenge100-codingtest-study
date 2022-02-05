N = int(input())
nums = list(map(int, input().split()))
increase = []
decrease = []
for i in range(N):
    increase.append(max([1]+[increase[j]+1 if nums[j] < nums[i] else 1 for j in range(i)]))
    decrease.insert(0, max([1]+[decrease[j]+1 if nums[j] < nums[-i-1] else 1 for j in range(-1, -i-1, -1)]))
print(max([increase[i]+decrease[i]-1 for i in range(N)]))