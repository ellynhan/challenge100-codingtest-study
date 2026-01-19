'''
문제 :
2차원 행렬 arr1과 arr2를 입력받아, arr1에 arr2를 곱한 결과를 반환하는 함수, solution을 완성해주세요.
제한 조건 :
행렬 arr1, arr2의 행과 열의 길이는 2 이상 100 이하입니다.
행렬 arr1, arr2의 원소는 -10 이상 20 이하인 자연수입니다.
곱할 수 있는 배열만 주어집니다.
'''

import numpy as np

def solution(arr1, arr2):
    A = np.array(arr1)
    B = np.array(arr2)
   
    return (A @ B).tolist()


# 행렬을 입력받는다면?
'''
import numpy as np

a1,b1=map(int, input("첫번째 행렬의 행과 열 크기 입력: ").split())
if not (2 <= a1 <= 100 and 2 <= b1 <= 100):
  raise ValueError("행렬 크기는 2 이상 100 이하로 입력")

print("첫번째 행렬의 원소값을 입력 (각 행은 한 줄씩, 공백으로 구분) : ")
A=np.array([list(map(int, input().split())) for _ in range(a1)])
if not np.all((-10 <= A) & (A <= 20)):
    raise ValueError("행렬 원소는 -10 이상 20 이하로 입력")
 
a2,b2=map(int, input("두번째 행렬의 행과 열 크기 입력: ").split())
if not (2 <= a2 <= 100 and 2 <= b2 <= 100):
  raise ValueError("행렬 크기는 2 이상 100 이하로 입력")

print("두번째 행렬의 원소값을 입력 (각 행은 한 줄씩, 공백으로 구분) : ")
B=np.array([list(map(int, input().split())) for _ in range(a2)])
if not np.all((-10 <= B) & (B <= 20)):
    raise ValueError("행렬 원소는 -10 이상 20 이하로 입력")

if b1 != a2:
  print("행렬 곱 불가(각 행렬의 크기를 연산 가능한 크기로 조정하세요)")
else:
  C = A @ B  

  print("\n행렬 곱 결과:")
  print(C)
'''
