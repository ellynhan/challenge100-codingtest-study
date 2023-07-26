# 파이썬 라이브러리에서 구현한 방식 - 외워버려 걍!!!!!!
def bisect_left(l, a):
    left = 0
    right = len(l)
    while left<right:
        # print(left, right)
        mid = (left+right) // 2
        if l[mid] < a:
            # result = mid
            left = mid+1
        elif l[mid] >= a:
            right = mid
    return left

def bisect_right(l, a):
    left = 0
    right = len(l)
    while left<right:
        # print(left, right)
        mid = (left+right) // 2
        if l[mid] <= a:
            # result = mid
            left = mid+1
        elif l[mid] > a:
            right = mid
    return left

# from bisect import bisect_right

n = int(input())
crane = sorted(list(map(int, input().split(" "))), reverse= True)
m = int(input())
boxes = sorted(list(map(int, input().split(" "))))

# print(crane, boxes)

answer=0
if max(crane)<max(boxes):
    print(-1)
else:
    while boxes:
        for c in crane:
            # if not boxes:
            #     break
            idx = bisect_right(boxes, c)
            # print(boxes, c, idx)
            # if idx ==0 and boxes[idx]>=c:
            #     break
            # if idx -1 >=0 and boxes[idx-1]<=c:
            #     idx-=1
            if boxes and boxes[idx-1] <= c:
                boxes.pop(idx-1)
        answer+=1
    print(answer)
    
