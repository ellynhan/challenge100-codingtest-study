# 이름이 입력되긴 했는데 상사가 없으면, Boss!
# 부하 자리에서 나타난 적이 없으면, 상사가 없다는 뜻.
from collections import defaultdict


def get_dist(prv):
    for cur in mafia_tree[prv]:
        mafia_data[cur].append(mafia_data[prv][0]+1)
        get_dist(cur)


def get_sub(cur):
    sub_sum = 0
    for nxt in mafia_tree[cur]:
        sub_sum += 1 + get_sub(nxt)
    mafia_data[cur].append(sub_sum)
    return sub_sum


n = int(input())
mafia_tree = defaultdict(list)
boss_set = set()
person_set = set()
mafia_data = defaultdict(list)

for _ in range(n-1):
    person, boss = input().split()
    mafia_tree[boss] += [person]
    boss_set.add(boss)
    person_set.add(person)

root_node = (boss_set - person_set).pop()
mafia_data[root_node] = [0]
get_dist(root_node)
get_sub(root_node)

# mafia_data.items() -> ("이름", [보스와의 거리, 부하들의 수])
sorted_mafia = sorted(mafia_data.items(), key=lambda item: (-item[1][1], item[1][0], item[0]))
for mafia in sorted_mafia:
    print(mafia[0])
