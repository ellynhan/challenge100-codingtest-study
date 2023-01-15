'''
==============================================================================================
@ Title: 1
@ URL: https://www.acmicpc.net/problem/4375
@ Author: jopemachine
@ Created Date: 12/10/2022, 2:17:39 PM
@ Level: Silver 3
@ Description:
2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾는 프로그램을
작성하시오.
@ Input: 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다.
@ Output: 1로 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.
==============================================================================================
'''

while True:
  try:
    N = int(input())
    i = '1'
    ans = -1

    while True:
      if int(i) % N == 0:
        ans = len(i)
        break
      i += '1'

    print(ans)

  except:
    break
