def solution(players, callings):
    orders = {p: i for i, p in enumerate(players)}
    for p in callings:
        i = orders[p]
        j = orders[p]-1
        orders[players[j]] += 1
        orders[p] -= 1
        players[i], players[j] = players[j], players[i]
    return players
