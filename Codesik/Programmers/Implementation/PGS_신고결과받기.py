from collections import defaultdict

def solution(id_list, report, k):
    answer = []
    report_log = defaultdict(set)
    report_cnt = defaultdict(int)
    for id in id_list:
        report_log[id]
        report_cnt[id]

    for r in report:
        report_from, report_to = r.split(' ')
        report_log[report_from].add(report_to)

    for key, value in report_log.items():
        for v in value:
            report_cnt[v] += 1

    # print(report_log, report_cnt)

    for key, value in report_log.items():
        cnt = 0
        for v in value:
            if report_cnt[v] >= k:
                cnt += 1
        answer.append(cnt)

    return answer