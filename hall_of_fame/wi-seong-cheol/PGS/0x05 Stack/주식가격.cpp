//
//  주식가격.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Level 2
// Timer: 12m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>
#include <stack>

using namespace std;
#define X first
#define Y second

vector<int> solution(vector<int> prices) {
    
    vector<int> answer;
    stack<pair<int, int>> stock;
    
    for(size_t i = 0; i < prices.size(); i++) {
        while(!stock.empty() && prices[i] < stock.top().X) {
            answer[stock.top().Y] = i - stock.top().Y;
            stock.pop();
        }
        stock.push(make_pair(prices[i], i));
        answer.push_back(prices.size() - i - 1);
    }
    
    
    return answer;
}
