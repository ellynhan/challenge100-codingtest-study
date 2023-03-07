import itertools

def solution(k, dungeons):
    answer = 0
    # 최소 피로도, 소모 피로도, 최대한 많이 던던 탐험, 현재 피로도 k
    # [0,1,2] [0,2,1]
    # [1,2,0] [1.0,2]
    # [2,0,1] [2,1,0]

    for i in itertools.permutations(dungeons, len(dungeons)):
        hp = k
        survive = 0
        dun_per = list(i)
        for dungeon in dun_per:
            if hp >= dungeon[0]:
                hp -= dungeon[1]
                survive += 1

        if survive > answer:
            answer = survive
        else:
            continue

    return answer
