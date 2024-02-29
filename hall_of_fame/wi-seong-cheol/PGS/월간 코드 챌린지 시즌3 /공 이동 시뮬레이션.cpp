//
//  공 이동 시뮬레이션.cpp
//  main
//
//  Created by wi_seong on 2/5/24.
//

// 시간복잡도: O(n)
// 최악시간: 200,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/87391

#include <string>
#include <vector>

using namespace std;
typedef long long ll;
int N, M;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> calcNextRange(int s, int e, int move, int max) {
    int nextS = (s == 0 && move > 0) ? 0 : s + move;
    int nextE = (e == max - 1 && move < 0 ) ? max - 1 : e + move;

    if((nextS < 0 || nextS >= max) && (nextE < 0 || nextE >= max)) {
        return {-1, -1};
    }
    if(nextS < 0 && nextE >= 0 && nextE < max) {
        return {0, nextE};
    }
    if(nextE >= max && nextS >= 0 && nextS < max) {
        return {nextS, max - 1};
    }

    return {nextS, nextE};
}

long long solve(int targetX, int targetY, const vector<vector<int>>& queries) {
    int sx, ex, sy, ey;
    sx = ex = targetX;
    sy = ey = targetY;
    int dir, x;

    for(int i = int(queries.size()) - 1; i >= 0; i--) {
        dir = queries[i][0];
        x = queries[i][1];

        if(dir == 0 || dir == 1) {
            auto result = calcNextRange(sy, ey, x * dy[dir], M);
            if(result.first == -1) return 0;
            sy = result.first;
            ey = result.second;
        } else {
            auto result = calcNextRange(sx, ex, x * dx[dir], N);
            if(result.first == -1) return 0;
            sx = result.first;
            ex = result.second;
        }
    }

    return ll(ex - sx + 1) * ll(ey - sy + 1);
}

ll solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    ll answer = 0;
    N = n;
    M = m;

    answer = solve(x, y, queries);

    return answer;
}
