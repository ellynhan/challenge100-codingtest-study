//
//  다단계 칫솔 판매.cpp
//  main
//
//  Created by wi_seong on 1/31/24.
//

// 시간복잡도: O(n * m)
// 최악시간: 1,000,000,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/77486#

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> nameToIdx, cost, result;
unordered_map<int, string> idxToName;
int parents[10001];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int n = int(enroll.size());
    int m = int(seller.size());

    for(int i = 1; i <= n; i++) {
        string name = enroll[i - 1];
        nameToIdx[name] = i;
        idxToName[i] = name;
    }

    for(int i = 1; i <= n; i++) {
        int child = i;
        if(referral[i - 1] != "-") {
            int parent = nameToIdx[referral[i - 1]];
            parents[child] = parent;
        }
    }

    for(int i = 0; i < m; i++) {
        int cost = amount[i] * 100;
        string sellerName = seller[i];
        result[sellerName] += cost - (cost / 10);
        cost /= 10;

        int cur = nameToIdx[sellerName];
        while(true) {
            if(parents[cur] == 0) break;
            int nxt = parents[cur];
            string parentName = idxToName[nxt];
            result[parentName] += cost - (cost / 10);
            cost /= 10;
            if(cost == 0) break;
            cur = nxt;
        }
    }

    for(int i = 0; i < n; i++) {
        string name = enroll[i];
        answer.push_back(result[name]);
    }

    return answer;
}
