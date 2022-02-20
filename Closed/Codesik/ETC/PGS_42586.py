# 1 24 10분
def solution(progresses, speeds):
    answer = []
    while progresses:
        deploy_list = []
        for i in range(len(progresses)):
            if i == 0 and progresses[i] >= 100:
                deploy_list.append(i)
                continue

            if (i - 1) in deploy_list and progresses[i] >= 100:
                deploy_list.append(i)

        if len(deploy_list) > 0:
            answer.append(len(deploy_list))

        for _ in range(len(deploy_list)):
            progresses.pop(0)
            speeds.pop(0)

        for i in range(len(progresses)):
            progresses[i] += speeds[i]

    return answer