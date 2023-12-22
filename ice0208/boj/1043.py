import sys

input = sys.stdin.readline


def union(a, b):
    p_a, p_b = find(a), find(b)

    if p_a < p_b:
        parent[p_b] = p_a
    else:
        parent[p_a] = p_b


def find(k):
    if parent[k] != k:
        parent[k] = find(parent[k])

    return parent[k]


if __name__ == "__main__":
    N, M = map(int, input().split())
    know_info = list(map(int, input().split()))
    know_cnt = know_info[0]
    know_list = know_info[1:]

    parent = [i for i in range(N + 1)]

    partys_list = []

    for _ in range(M):
        party_info = list(map(int, input().split()))
        party_cnt = party_info[0]
        party_list = party_info[1:]
        partys_list.append(party_list)

        for i in range(len(party_list) - 1):
            union(party_list[i], party_list[i + 1])

    know_parent_set = set()
    for know_person in know_list:
        know_parent_set.add(find(know_person))
    answer = 0
    for party_list in partys_list:
        has_know_person = False
        if find(party_list[0]) in know_parent_set:
            continue
        answer += 1
    print(answer)
