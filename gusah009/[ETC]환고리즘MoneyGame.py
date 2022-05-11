import sys

inp = input().strip().split()

MAX = 31

operator = []
operand = []
dp_max = [[-sys.maxsize - 1 for col in range(MAX)] for row in range(MAX)]
dp_min = [[sys.maxsize for col in range(MAX)] for row in range(MAX)]
answer = -sys.maxsize - 1

def operate(num1, oper, num2):
  if oper == '*':
    return num1 * num2
  elif oper == '+':
    return num1 + num2
  elif oper == '-':
    return num1 - num2

def input():
  global operand, operator
  for i, v in enumerate(inp):
    if i % 2 == 0:
      operand.append(int(v))
    else:
      operator.append(v)

def init():
  global operand, operator, dp_max, dp_min
  for i, v in enumerate(operand):
    dp_max[i][i] = v
    dp_min[i][i] = v

def solve():
  global operand, operator, dp_max, dp_min, answer
  init()
  for i in range(len(operand)):
    size = i + 1
    for j in range(len(operand) - size):
      for k in range(size):
        result1 = operate(dp_max[j][j + k], operator[j + k], dp_max[j + k + 1][j + size])
        result2 = operate(dp_min[j][j + k], operator[j + k], dp_max[j + k + 1][j + size])
        result3 = operate(dp_max[j][j + k], operator[j + k], dp_min[j + k + 1][j + size])
        result4 = operate(dp_min[j][j + k], operator[j + k], dp_min[j + k + 1][j + size])
        dp_max[j][j + size] = max(dp_max[j][j + size], result1, result2, result3, result4)
        dp_min[j][j + size] = min(dp_min[j][j + size], result1, result2, result3, result4)

  answer = dp_max[0][len(operand) - 1]

if __name__ == "__main__":
  input()
  solve()
  print(answer)

  # for i in range(len(operand)):
  #   for j in range(len(operand)):
  #     print(dp_max[i][j], end = '\t')
  #   print()
  # print()
  # for i in range(len(operand)):
  #   for j in range(len(operand)):
  #     print(dp_min[i][j], end = '\t')
  #   print()