//
//  교점에 별 만들기.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/87377#

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<string> solution(vector<vector<int>> line) {
    int n = int(line.size());
    vector<pair<int, int>> points;
    int mnX, mnY, mxX, mxY;
    mnX = mnY = INT_MAX;
    mxX = mxY = INT_MIN;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int ADBC = (line[i][0] * line[j][1]) - (line[i][1] * line[j][0]);
            ll BFED = (1LL * line[i][1] * line[j][2]) - (1LL * line[i][2] * line[j][1]);
            ll ECAF = (1LL * line[i][2] * line[j][0]) - (1LL * line[i][0] * line[j][2]);

            if(ADBC == 0) continue;
            if(BFED % ADBC || ECAF % ADBC) continue;
            int x = BFED / ADBC;
            int y = ECAF / ADBC;
            mnX = min(mnX, x);
            mxX = max(mxX, x);
            mnY = min(mnY, y);
            mxY = max(mxY, y);
            points.push_back({x, y});
        }
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    string s(mxX - mnX + 1, '.');
    vector<string> answer(mxY - mnY + 1, s);

    for(auto point: points) {
        answer[-point.second + mxY][point.first - mnX] = '*';
    }

    return answer;
}
