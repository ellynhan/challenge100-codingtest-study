def solution(players, callings):
    answer = []
    players_dict = {}
    rank_dict = {} # 순서 swap를 위해서 요소를 검색할때 
    
    for index, value in enumerate(players):
        players_dict[index] = value
        rank_dict[value] = index
    
    #print(players_dict, rank_dict)
    
    for j in callings:
        call_rank = rank_dict[j] # 부른 선수 순위 가져오기
        front_player = players_dict[call_rank-1] # 앞 선수 이름 가져오기
        #print(call_rank, j)
        #print(call_rank-1, front_player)
        
        players_dict[call_rank], players_dict[call_rank-1] = front_player, j
        rank_dict[j], rank_dict[front_player] = call_rank-1, call_rank
    
    #print(rank_dict, players_dict)
    answer = list(players_dict.values())

    return answer
