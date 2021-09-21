"""
def solution(s):
    answer = 0
    result = int(999999)
    s_length = len(s)
    k = len(s)//2+1
    for i in range(1, k+1):
      repeat = 0
      slc = i
      st = s[0:slc]
      length = len(st)
      while slc<s_length:
        if st == s[slc:slc+i]:
          repeat += 1
          if repeat == 1 or repeat == 9 or repeat == 99:
            length += 1
        else:
          st = s[slc:slc+i]
          length += len(st)
          repeat = 0 
        slc = slc+i
      print(length,'')
      if result > length:
        result = length
    
    answer = result
          
    return answer

data = input()
r = solution(data)
"""
def solution(s):
  answer = len(s)

  for step in range(1, len(s)//2+1):
    compressed = ""
    prev = s[0:step]
    count = 1

    for j in range(step,len(s),step):
      if prev == s[j:j+step]: #이전 상태와 동일하면 압축 횟수(count) 증가
        count += 1
      else:#다른 문자열이 나오면
        compressed += str(count) + prev if count >= 2 else prev
        prev = s[j:j+step]
        count = 1
    #남아 있는 문자열에 대해서 처리
    compressed += str(count) + prev if count >= 2 else prev
    answer = min(answer, len(compressed))
    
  return answer
