def solution(phone_book):
    answer = True

    # phone book의 모든 번호 중 하나가 다른 번호가 접두어면 false
    dict = {}
    phone_book.sort()
    
    # key값만 있는 해시 생성
    for i in range(len(phone_book)):
        dict[phone_book[i]] = 1 # value는 1으로 통합
    
    for number in phone_book:
        makeword = ''
        for num in number:
            makeword += num
            if makeword in dict and number != makeword:
                # print(number, makeword)
                answer = False
                break
    
    return answer
