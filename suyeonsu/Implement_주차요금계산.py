from math import ceil

def solution(fees, records):
    
    def calc(sh, sm, eh, em):
        if sm > em:
            eh -= 1
            em += 60
        return (eh - sh) * 60 + em - sm

    def charge(m):
        dm, df, per, perf = fees
        if m <= dm: return df
        return df + ceil((m-dm) / per) * perf
    
    cars = dict()
    times = dict()
    for r in records:
        t, num, st = r.split()
        if st == 'IN':
            if num not in times: times[num] = 0
            cars[num] = t
        else:
            s = cars.pop(num).split(":")
            e = t.split(":")
            times[num] += calc(int(s[0]), int(s[1]), int(e[0]), int(e[1]))
    if cars:
        for num, t in cars.items():
            s = t.split(":")
            times[num] += calc(int(s[0]), int(s[1]), 23, 59)

    answer = [(c, charge(t)) for c, t in times.items()]
    answer.sort()
    
    return [fee for c, fee in answer]

# 어떤 자료형을 쓸지, 그리고 주어진 레코드를 어떻게 처리해야 깔끔한지 고민하느라 시간이 좀 걸렸다.
