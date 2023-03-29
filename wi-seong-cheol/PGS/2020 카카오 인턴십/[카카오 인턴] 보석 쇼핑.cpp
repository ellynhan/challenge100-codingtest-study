//
//  [카카오 인턴] 보석 쇼핑.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/09.
//

// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Level 3
// Timer: 50m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/67258

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string, int> gemNumber;
int gemCount[100001];   // 보석 갯수

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    int n = gems.size();
    int idx = 1;
    
    for(string gem: gems)
        if(gemNumber[gem] == 0)
            gemNumber[gem] = idx++;
    
    int gemCnt = gemNumber.size();
    int en = 1;
    int cnt = 0;
    int len = n + 1;
    for(int st = 1; st <= n; st++) {
        while(en <= n && cnt != gemCnt) {
            string gemName = gems[en - 1];
            int gemIdx = gemNumber[gemName];
            gemCount[gemIdx]++;
            if(gemCount[gemIdx] == 1)
                cnt++;
            en++;
        }
        if(cnt == gemCnt && len > en - st) {
            answer[0] = st;
            answer[1] = en - 1;
            len = en - st;
        }
        string gemName = gems[st - 1];
        int gemIdx = gemNumber[gemName];
        gemCount[gemIdx]--;
        if(gemCount[gemIdx] == 0)
            cnt--;
    }
    
    return answer;
}
