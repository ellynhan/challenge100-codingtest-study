def solution(id_list, report, k):
    user_reported = {} #신고당한 유저
    count = {} # 처리 결과 메일을 받은 유저
    
    # 신고당한 유저 key : 신고한 유저 리스트 value
    for r in report:
        fr, to = r.split()
        if to not in user_reported:
            user_reported[to] = set()
        user_reported[to].add(fr)
    
    # user_reported에 저장된 정보를 기준으로 신고당한 횟수가 k번 이상이면 count 추가
    # count : 메일을 보낼 횟수
    for reported, report_user_list in user_reported.items():
        if len(report_user_list)>=k:
            for user in report_user_list:
                if user not in count:
                    count[user] = 1
                else:
                    count[user] += 1
    
    answer = []
    for i in range(len(id_list)):
        if id_list[i] not in count:
            answer.append(0)
        else:
            answer.append(count[id_list[i]])
    
    return answer
    
"""
    answer = []
    user = {id:[] for id in id_list} # id:key , value: 신고한 사람 목록
    user_reported = {id:0 for id in id_list} # id:key, value: 신고당한 횟수
    report_set = set() # report가 중복되지 않게 set으로 설정
    
    # 누가 누구를 신고했는지 set에 저장
    for repo in report:
        fr, to = repo.split()
        report_set.add((fr,to))
    
    for fr, to in report_set:
        user[fr].append(to)
        user_reported[to] +=1
    
    suspension = [key for key,value in user_reported.items() if value>=k]
    
    for key, value in user.items():
        count = 0
        for val in value:
            if val in suspension:
                count += 1
        answer.append(count)
    
    
    return answer
"""