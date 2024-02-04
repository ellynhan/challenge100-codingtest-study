//
//  가장 많이 받은 선물.cpp
//  main
//
//  Created by wi_seong on 1/24/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 2,500
// 난이도: Level 1
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/258712

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

unordered_map<string, int> f2i;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = int(friends.size());
    vector<vector<int>> charts(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        f2i[friends[i]] = i;
    }

    for(string gift: gifts) {
        vector<string> input;
        stringstream ss(gift);
        string token;

        while(getline(ss, token, ' ')) {
            input.push_back(token);
        }
        charts[f2i[input[0]]][f2i[input[1]]]++;
    }

    vector<int> points(n);
    for(int i = 0; i < n; i++) {
        int gift = 0;
        int take = 0;
        for(int j = 0; j < n; j++) {
            gift += charts[i][j];
        }
        for(int j = 0; j < n; j++) {
            take += charts[j][i];
        }
        points[i] = gift - take;
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(charts[i][j] == charts[j][i]) {
                if(points[i] > points[j]) sum++;
            } else if(charts[i][j] > charts[j][i]) {
                sum++;
            }
        }
        answer = max(answer, sum);
    }

    return answer;
}
