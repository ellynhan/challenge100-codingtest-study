//
//  아날로그 시계.cpp
//  main
//
//  Created by wi_seong on 2/16/24.
//

// 시간복잡도: O(n)
// 최악시간: 86,400
// 난이도: Level 2
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/250135

#include <string>
#include <vector>

using namespace std;

int to_second(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

vector<int> to_hms(int sec) {
    vector<int> ret(3);
    ret[0] = sec / 3600;
    sec %= 3600;
    ret[1] = sec / 60;
    sec %= 60;
    ret[2] = sec % 60;
    return ret;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int totalTime = to_second(23, 59, 59);
    int startTime = to_second(h1, m1, s1);
    int endTime = to_second(h2, m2, s2);

    vector<int> table(totalTime + 1);

    for (int i = 0; i < totalTime; i++) {
        int cnt = 0;
        auto curr_time = to_hms(i);
        double hAngle = curr_time[0] * 30 + curr_time[1] * 0.5 + curr_time[2] * 1 / 120;
        double mAngle = curr_time[1] * 6 + curr_time[2] * 0.1;
        double sAngle = curr_time[2] * 6;

        while(hAngle >= 360) hAngle -= 360;
        while(mAngle >= 360) mAngle -= 360;
        while(sAngle >= 360) sAngle -= 360;

        auto next_time = to_hms(i + 1);
        double n_hAngle = next_time[0] * 30 + next_time[1] * 0.5 + next_time[2] * 1 / 120;
        double n_mAngle = next_time[1] * 6 + next_time[2] * 0.1;
        double n_sAngle = next_time[2] * 6;

        while(n_hAngle >= 360)n_hAngle -= 360;
        while(n_mAngle >= 360) n_mAngle -= 360;
        while(n_sAngle >= 360) n_sAngle -= 360;

        if (sAngle < mAngle && n_sAngle >= n_mAngle) {
            cnt++;
        } else if(sAngle == 354 && mAngle > 354) {
            cnt++;
        }
        if (sAngle < hAngle && n_sAngle >= n_hAngle) {
            cnt++;
        } else if(sAngle == 354 && hAngle > 354) {
            cnt++;
        }

        table[i + 1] = cnt;
    }

    table[0] = 1;
    table[43200] = 1;

    if(startTime == 0 || startTime == 43200) answer++;
    for (int i = startTime+1; i <= endTime; i++) {
        answer += table[i];
    }

    return answer;
}
