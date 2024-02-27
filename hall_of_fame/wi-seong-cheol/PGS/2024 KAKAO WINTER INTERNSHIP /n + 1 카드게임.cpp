//
//  n + 1 카드게임.cpp
//  main
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/258707

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;
int N;

bool removeDeck(unordered_set<int>& deck1, unordered_set<int>& deck2) {
    for(int val: deck1) {
        int findCard = N + 1 - val;
        if(deck2.find(findCard) != deck2.end()) {
            deck1.erase(val);
            deck2.erase(findCard);
            return true;
        }
    }

    return false;
}

int solve(int coin, unordered_set<int>& hands, vector<int>& cards) {
    int ret = 0;
    int curIdx = (N / 3);
    unordered_set<int> draw;

    while(curIdx < N) {
        for(int i = 0; i < 2; i++) {
            draw.insert(cards[curIdx++]);
        }

        if(hands.size() >= 2 && removeDeck(hands, hands)) {
            ret++;
        } else if(hands.size() >= 1 && coin >= 1 && removeDeck(hands, draw)) {
            coin--;
            ret++;
        } else if(coin >= 2 && removeDeck(draw, draw)) {
            coin -= 2;
            ret++;
        } else {
            break;
        }
    }

    return ret;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    N = int(cards.size());
    unordered_set<int> hands(cards.begin(), cards.begin() + (N / 3));

    answer = solve(coin, hands, cards) + 1;

    return answer;
}
