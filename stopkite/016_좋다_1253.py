n = int(input())

arr = list(map(int, input().split()))
arr.sort()

count = 0
for i in range(len(arr)):
    target = arr[i]
    left, right = 0, len(arr) - 1

    while left < right:
        if left == i:
            left += 1
            continue
        if right == i:
            right -= 1
            continue

        current_sum = arr[left] + arr[right]

        if current_sum == target:
            count += 1
            break
        elif current_sum < target:
            left += 1
        else:
            right -= 1

print(count)
