from heapq import heappop, heappush, heapify

def solution(operations) :
    
    answer = []
    storage = []
    
    for operation in operations :
        if operation[0] == 'I' :
            heappush(storage, int(operation[2:]))
        else :
            if not storage :
                continue
                
            if operation[2] == '-' :
                heappop(storage)
            else :
                storage.remove(max(storage))
                heapify(storage)
                
    if not storage : return [0, 0]
    answer = [max(storage), storage[0]]
    
    return answer
