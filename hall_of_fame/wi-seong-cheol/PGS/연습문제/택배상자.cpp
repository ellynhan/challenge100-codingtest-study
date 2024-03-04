//
//  택배상자.cpp
//  main
//
//  Created by wi_seong on 2/11/24.
//

// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/131704

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> belt;
    stack<int> sub;
    int n = int(order.size());

    for(int i = 1; i <= n; i++) {
        belt.push_back(i);
    }
    int beltPos = 0;
    int orderPos = 0;

    while(orderPos < n) {
        if(beltPos < n && belt[beltPos] == order[orderPos]) {
            answer++;
            beltPos++;
            orderPos++;
        } else if(!sub.empty() && sub.top() == order[orderPos]) {
            answer++;
            orderPos++;
            sub.pop();
        } else if(beltPos < n) {
            sub.push(belt[beltPos++]);
        } else {
            break;
        }
    }

    return answer;
}
