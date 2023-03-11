def two(input_list):
    output_list = []

    for i in range(len(input_list)):
        if i < len(input_list)-1:
            word = input_list[i] + input_list[i+1]
            if word.isalpha():
                output_list.append(word)
    return output_list

# 교집합 / 합집합
# 공집합 = 1
# 곱하기 65536 후에 정수부분만 추출
def solution(str1, str2):
    answer = 0
    str1 = str1.lower()
    str2 = str2.lower()
    
    list1 = two(str1)
    list2 = two(str2)
    print(list1)
    print(list2)
    
    list2_temp = list2.copy() # 합집합을 구하기 위한 차집합
    union = list2.copy() # 합집합
    intersection = [] # 교집합
    
    for i in list1:
        if i in list2:
            list2.remove(i)
            intersection.append(i)
        
        if i not in list2_temp:
            union.append(i)
        else:
            list2_temp.remove(i)
    
    # print(union)
    # print(intersection)

    if len(union) == 0: 
        answer = 65536
    else:
        answer = len(intersection) / len(union) * 65536
    
    return int(answer)

