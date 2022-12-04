# [방법1] 정렬 -> 효율성 테스트 결과가 [방법2]보다 좋았음
def solution(phone_book):
    phone_book.sort()
    for a, b in zip(phone_book, phone_book[1:]):
        if b.startswith(a): return False
    return True

  
# [방법2] Hash
def solution(phone_book):
    h = {num:1 for num in phone_book}
    for num in phone_book:
        pre = ''
        for k in num:
            pre += k
            if pre in h and pre != num:
                return False
    return True
  
  
"""
문자열 리스트 정렬시 사전순으로 정렬됨
startswith(시작하는 문자(열), 시작지점)
endswith(끝나는 문자(열), 문자열의 시작, 문자열의 끝)
"""
