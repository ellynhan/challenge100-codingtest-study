def solution(arr):
    ans = []
    top = -1
    for i in arr:
        if top == -1:
            ans.append(i)
            top += 1
        elif ans[top] != i:
            ans.append(i)
            top += 1
    return ans
