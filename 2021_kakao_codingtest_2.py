import itertools
import collections

def solution(orders, course):
    def dict_default():
        return 0
    answer = []
    courses = collections.defaultdict(dict_default)
    for order in orders:
        for i in range(2,len(order)+1):
            order_list = sorted(list(order))
            combination_list = itertools.combinations(order_list,i)
            for elem in combination_list:
                elem1 = ''.join(elem)
                courses[elem1]+=1
                
    elem_max = {k:[0,[]] for k in course}
    
    for key, value in courses.items():
        if len(key) in course  and elem_max[len(key)][0] < value:
            elem_max[len(key)] = [value, [key]]
        elif (len(key) in course) and elem_max[len(key)][0] == value:
            elem_max[len(key)][1].append(key)
            
    for val in elem_max.values():
        if val[0] >= 2:
            answer += val[1]
        
    answer.sort()
    
    return answer
