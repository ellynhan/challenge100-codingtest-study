//
//  외벽 점검.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/02.
//

// 시간복잡도: O((2 ^ n) * n ^ 3)
// 최악시간: 864,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/60062

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF;
    int w_size = weak.size();
    
    for(int i = 0; i < n - 1; i++)
        weak.push_back(weak[i] + n);
    
    sort(dist.begin(), dist.end());
    do {
        for(int i = 0; i < w_size; i++) {
            int st = weak[i];
            int en = weak[i + w_size - 1];
            for(int j = 0; j < dist.size(); j++) {
                st += dist[j];
                
                if(st >= en) {
                    answer = min(answer, j + 1);
                    break;
                }
                
                for(int k = i + 1; k < i + w_size; k++) {
                    if(weak[k] > st) {
                        st = weak[k];
                        break;
                    }
                }
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == INF) return -1;
    return answer;
}
