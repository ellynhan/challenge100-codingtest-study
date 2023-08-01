# 조이스틱
# 문제 잘 읽기 : 한번 오른쪽 끝으로 가면 못돌아옴
import string
from collections import defaultdict

def solution(name):
    answer = 0

    def continuous_A_count(name):
        count = [0 if name[i]!='A' else 1 for i in range(len(name))]
        count[0] = 0
        for i in range(1,len(name)):
            if name[i-1]=='A' and count[i]!=0 :
                count[i] = count[i-1]+1
        return (count.index(max(count))) - max(count), max(count)
    
    def change_alphabet(char):
        return min(ord(char)- ord('A'), ord('Z')+1 -ord(char))
        
    a,b = continuous_A_count(name)
    answer += min(len(name)-1, len(name)-1 - b + a)
    for alphabet in name:
        answer+= change_alphabet(alphabet)
            
    return answer

print(solution("ABAAAAAAAAABB"))


# continuous_A_count_mapx("AANAAA")
