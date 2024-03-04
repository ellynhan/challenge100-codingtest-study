//
//  구명보트.cpp
//  main
//
//  Created by wi_seong on 2/7/24.
//

// 시간복잡도: O(n)
// 최악시간: 50,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int st = 0;
    int en = int(people.size()) - 1;

    while(st <= en) {
        if(st != en && people[st] + people[en] <= limit) {
            st++; en--;
        } else {
            en--;
        }
        answer++;
    }


    return answer;
}
