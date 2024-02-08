def solution(enroll, referral, seller, amount):
    parent = dict(zip(enroll, referral))
    # 이름 키 : 수익 값 
    total_money = {name:0 for name in enroll}
    
    for i in range(len(seller)):
        money = amount[i]*100
        cur_name = seller[i]
        while money > 0 and cur_name != "-":
            #1원 미만으로는 분배하지 않음 (//10)
            total_money[cur_name] += money - money//10
            cur_name = parent[cur_name]
            money //= 10
    
    return [total_money[name] for name in enroll]