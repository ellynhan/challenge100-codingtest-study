//
//  캠핑.cpp
//  main
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 125,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1833

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> data) {
    int answer = 0;

    sort(data.begin(), data.end());

    for(int i = 0; i < n - 1; i++) {
        int x1 = data[i][0];
        int y1 = data[i][1];
        for(int j = i + 1; j < n; j++) {
            int x2 = data[j][0];
            int y2 = data[j][1];
            if(x1 == x2 || y1 == y2) continue;

            bool flag = true;
            for(int k = i + 1; k < j; k++) {
                int x3 = data[k][0];
                int y3 = data[k][1];
                if(x1 < x3 && x3 < x2 && min(y1, y2) < y3 && y3 < max(y1, y2)) {
                    flag = false;
                    break;
                }
            }
            if(flag) answer++;
        }
    }

    return answer;
}
