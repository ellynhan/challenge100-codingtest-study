//
//  과제 진행하기.cpp
//  main
//
//  Created by wi_seong on 2/15/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Level 2
// Timer: 40m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/176962

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Plan {
    string title;
    int start, due;
};

bool cmp(const Plan& p1, const Plan& p2) {
    return p1.start < p2.start;
}

int parseTime(string& t) {
    string hour = t.substr(0, 2);
    string minute = t.substr(3, 2);
    return stoi(hour) * 60 + stoi(minute);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Plan> p;

    for(auto plan: plans) {
        string title = plan[0];
        int start = parseTime(plan[1]);
        int due = stoi(plan[2]);
        p.push_back({title, start, due});
    }
    sort(p.begin(), p.end(), cmp);

    vector<Plan> ready;
    Plan current = p[0];

    for(int i = 1; i < int(p.size()); i++) {
        if(p[i].start >= current.start + current.due) {
            int remain = p[i].start - (current.start + current.due);
            answer.push_back(current.title);
            current = p[i];
            while(remain > 0) {
                if(ready.empty()) break;
                Plan readyPlan = ready.back(); ready.pop_back();
                if(remain - readyPlan.due < 0) {
                    readyPlan.due -= remain;
                    ready.push_back(readyPlan);
                    remain = 0;
                } else {
                    answer.push_back(readyPlan.title);
                    remain -= readyPlan.due;
                }
            }
        } else {
            int remain = (current.start + current.due) - p[i].start;
            current.due = remain;
            ready.push_back(current);
            current = p[i];
        }
    }
    answer.push_back(current.title);

    for(int i = int(ready.size()) - 1; i >= 0; i--) {
        answer.push_back(ready[i].title);
    }

    return answer;
}
