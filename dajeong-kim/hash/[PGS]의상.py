def solution(clothes):
    # answer = (각 타입에 해당하는 의상 종류의수를 모두 곱한 것) - 1
    hash_map = {}
    # type 키 : type에 해당하는 의상 종류의 수 value
    for cloth, typ in clothes:
        hash_map[typ] = hash_map.get(typ, 0) + 1
        
    answer = 1
    for typ in hash_map:
        answer *= (hash_map[typ] + 1)
    # 최소 한 개의 의상은 입어야 하므로 아무것도 안입은 상태의 경우의수 1을 빼줘야함
    return answer -1 