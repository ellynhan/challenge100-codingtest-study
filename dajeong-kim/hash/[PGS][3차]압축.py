def solution(msg):
    answer = []
    # 알파벳 A~Z까지 색인번호와 단어 dict에 등록
    dict = {chr(i+64):i for i in range(1,27)}
    num = 27 # 새로운 단어를 저장할 때 value로 쓸 값
    i = 0
    check = '' # 사전에 이미 있는지 체크하기 위한 용도
    while i < len(msg):
        check += msg[i]
        if check in dict:
            i+=1
        else:
            dict[check] = num
            num += 1
            answer.append(dict[check[:-1]])
            check = ''
    # 마지막에 check에 들어간 문자열 또는 문자의 경우 else문을 들어가지 못했기 때문에 append
    answer.append(dict[check])
    
    return answer