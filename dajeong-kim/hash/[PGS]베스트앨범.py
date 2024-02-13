def solution(genres, plays):
    answer = []
    genres_dict = {}
    plays_dict = {}
    
    for i in range(len(genres)):
        genre = genres[i]
        play = plays[i]
        # 키에 해당하는 값이 없는 경우 초기화값 명시
        if genre not in genres_dict:
            genres_dict[genre] = []
            plays_dict[genre] = 0
        genres_dict[genre].append((i,play))
        plays_dict[genre] += play
    
    # 각 장르의 재생수 총합을 기준으로 장르 순서 정렬
    sorted_genres = sorted(plays_dict.items(), key = lambda x:x[1], reverse=True)
    
    # 정렬된 각 장르에 대해 재생횟수와 고유번호를 기준으로 정렬 ([:2])
    for genre, _ in sorted_genres:
        sorted_songs = sorted(genres_dict[genre], key = lambda x: (-x[1], x[0]))
        answer.extend([idx for idx, _ in sorted_songs[:2]])
    
    return answer
