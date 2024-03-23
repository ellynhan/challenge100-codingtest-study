//
//  신고 결과 받기.cpp
//  main
//
//  Created by wi_seong on 3/22/24.
//

// 시간복잡도: O(n * m)
// 최악시간: 200,000
// 난이도: Level 1
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92334

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> r;
    unordered_map<string, int> reportCount;

    for(string report: reports) {
        stringstream ss(report);
        string token;
        vector<string> result;
        while(getline(ss, token, ' ')) {
            result.push_back(token);
        }

        r[result[0]].insert(result[1]);
    }

    for(auto element: r) {
        for(auto reportId: element.second) {
            reportCount[reportId]++;
        }
    }

    for(auto id: id_list) {
        int cnt = 0;
        for(auto reportId: r[id]) {
            if(reportCount[reportId] >= k) {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}
