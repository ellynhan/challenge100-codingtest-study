"""
def binary_search(array, target, start, end):
  #data가 1개 남아서 start와  end와 mid가 같아진 상태에서는 아래 두 elif에 들어갈 것이고, 결국 start가 end보다 커지게 되는 알고리즘. 그러므로 해당 조건문이 적합하다.
  if start>end:
    return None
  mid = (start+end)//2
  if array[mid] == target:
    return mid
  elif array[mid] > target:
    return binary_search(array, target, start, mid-1)
  elif array[mid] < target:
    return binary_search(array, target, mid+1, end)
  
n, target = list(map(int,input().split()))
array = list(map(int, input().split()))

result = binary_search(array, target, 0, n-1)

if result==None:
  print('찾고자 하는 target이 없습니다.')
else:
  print(result+1)
"""

def binary_search(array, target, start, end):
  while start<=end:
    mid = (start+end)//2
    if array[mid] == target:
      return mid
    elif array[mid] > target:
      end= mid-1
    elif array[mid] < target:
      start = mid+1
  return None

n, target = list(map(int, input().split()))
array = list(map(int, input().split()))

result = binary_search(array, target, 0, n-1)
