//
//  몸짱 트레이너 라이언의 고민.cpp
//  main
//
//  Created by wi_seong on 2/8/24.
//

// 시간복잡도: O(n ^ 6)
// 최악시간: 1,000,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1838

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 1e9 + 7;
struct Point {
    int x, y;
};

int calcLength(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool canPlaceFurther(Point coord, const int maxDistance, vector<Point> &people) {
    for(Point &p: people) {
        if(calcLength(p, coord) < maxDistance) {
            return false;
        }
    }
    return true;
}

int getMaxUser(int m, vector<vector<int>>& timetable) {
    sort(begin(timetable),end(timetable));
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(timetable[0][1]);

    for(int i = 1; i < m; i++) {
        pq.push(timetable[i][1]);
        if(pq.top() < timetable[i][0]) {
            pq.pop();
        }
    }

    return pq.size();
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
    int mxUser = getMaxUser(m, timetable);
    if(mxUser == 1) return 0;

    for(int distance = 2 * n - 2; distance > 0; distance--) {
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < n; x++) {
                if(x != 0 && y != 0) continue;
                vector<Point> people{{x,y}};
                for(int y2 = y; y2 < n; y2++) {
                    for(int x2 = 0; x2 < n; x2++) {
                        if(y2 == y && x2 <= x) continue;
                        if(canPlaceFurther({y2, x2}, distance, people)) {
                            people.push_back({y2, x2});
                        }

                        if(people.size() == mxUser) {
                            return distance;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
