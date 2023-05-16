"""
1 4 7 =
3 6 9 =
2 5 8 0 = 가까운 쪽, 같다면 오른속잡이, 왼손잡이
"""
def solution(numbers, hand):
    answer = ''
    left = 10
    right = 12
    
    for i in range(len(numbers)):
        #print(left, right)
        if numbers[i] == 0:
            numbers[i] = 11
        
        if numbers[i] == 1 or numbers[i] == 4 or numbers[i] == 7:
            answer += 'L'
            left = numbers[i]
        elif numbers[i] == 3 or numbers[i] == 6 or numbers[i] == 9:
            answer += 'R'
            right = numbers[i]
        else: # 2, 5 ,8, 0 일 경우
            l = abs(numbers[i] - left)
            r = abs(numbers[i] - right)
            dL = (l // 3) + (l % 3)
            dR = (r // 3) + (r % 3)
            #print(dL, dR)
            if dL > dR:
                print(left, right, numbers[i])
                answer += 'R'
                right = numbers[i]
            elif dL < dR:
                print(left, right, numbers[i])
                answer += 'L'
                left = numbers[i]
            elif dL == dR:       
                if hand == "right":
                    answer += 'R'
                    right = numbers[i]
                elif hand == "left":
                    answer += 'L'
                    left = numbers[i]
                
    
    return answer
