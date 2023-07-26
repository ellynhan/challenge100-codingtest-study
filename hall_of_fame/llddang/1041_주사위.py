def main():
  N = int(input());
  arr = input().split();
  arr = [int(x) for x in arr]

  answer = 0
  if N == 1:
    arr.sort()
    for i in range(5):
      answer += arr[i]
    print(answer)
    return

  answer = -1
  for i in range(6):
    for j in range(6):
      if i == j or 5 - i == j: continue
      for k in range(6):
        if i == k or 5 - i == k: continue
        if j == k or 5 - j == k: continue

        a, b, c = arr[i], arr[j], arr[k]

        semiAnswer = 0
        semiAnswer = semiAnswer + (a*(N-1)*N + b*N) * 4
        semiAnswer = semiAnswer + a*(N-2)*(N-2) + b*(N-2)*4 + c*4

        if answer == -1 or semiAnswer < answer:
          answer = semiAnswer
  
  print(answer)

if __name__ == "__main__":
  main()
