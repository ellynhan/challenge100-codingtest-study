# 해시를 이용한 풀이 O(N)
def solution(participant, completion):
    dict = {}
    for p in participant:
        if p in dict:
            dict[p] += 1
        else:
            dict[p] = 1
    
    for c in completion:
        dict[c] -= 1
    
    for key in dict.keys():
        if dict[key] != 0:
            return key
        
# collections.Counter를 이용한 풀이 O(N)
import collections

def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]

# 두 경우 모두 효율성 테스트에 동과하지만, 해시를 이용했을 때가 더 빠름