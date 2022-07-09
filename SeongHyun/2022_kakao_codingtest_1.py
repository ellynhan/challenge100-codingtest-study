def solution(id_list, report, k):
    answer = []
    report_set = set(report)
    result = {user:[] for user in id_list}
    alert_count = {user:0 for user in id_list}
    
    for elem in report_set:
        user, alert = elem.split(" ")
        result[user].append(alert)
        alert_count[alert]+=1
        
    for user in id_list:
        count = 0
        for alert in result[user]:
            if alert_count[alert] >=k:
                count+=1
        answer.append(count)
    return answer
