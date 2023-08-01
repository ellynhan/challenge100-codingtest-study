# https://programmers.co.kr/learn/courses/30/lessons/42579
# dict sort관련 블로그 : https://rfriend.tistory.com/473

from collections import defaultdict
def solution(genres, plays):
    num = len(genres)
    
    player = defaultdict(int) # 장르 재생 횟수
    player_index = defaultdict(list) # 장르별 인덱스 리스트
    for i in range(num):
        player[genres[i]] += plays[i]
        player_index[genres[i]].append(i)
        
    for genre in player_index:
        player_index[genre].sort(reverse = True, key = lambda x: plays[x]) # 잘 기억해두기, dict value로 sort하는 방법
    player = sorted(player.items(), reverse = True, key = lambda x: x[1])
    
    print(player, player_index)
    answer = []
    for genre, num in player:
        # print(player_index[genre][0])
        answer.append(player_index[genre][0])
        if (len(player_index[genre]) > 1):
            answer.append(player_index[genre][1])
            
    return answer