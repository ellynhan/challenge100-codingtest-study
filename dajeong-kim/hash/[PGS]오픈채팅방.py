def solution(record):
    # uid를 key, 닉네임을 value로 하는 딕셔너리
    uid_dict = {} 
    for line in record:
        cmd = line.split(" ")
        if cmd[0] != "Leave": #Enter또는 Change일때만 닉네임 값 변경됨
            uid_dict[cmd[1]] = cmd[2]
    
    answer = []
    for line in record:
        cmd = line.split(" ")
        
        if cmd[0] == "Enter":
            #answer.append("%s님이 들어왔습니다." % uid_dict[cmd[1]])
            answer.append(f"{uid_dict[cmd[1]]}님이 들어왔습니다.")
        elif cmd[0] == "Leave":
            #answer.append("%s님이 나갔습니다." % uid_dict[cmd[1]])
            answer.append(f"{uid_dict[cmd[1]]}님이 나갔습니다.")
    
    return answer