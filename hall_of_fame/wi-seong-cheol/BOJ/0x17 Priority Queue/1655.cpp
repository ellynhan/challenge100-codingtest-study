//
//  1655.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 1
 5
 2
 10
 -99
 7
 5
 [Output]
 1
 1
 2
 2
 2
 2
 5
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 2
// Timer: 22m
// Url: https://www.acmicpc.net/problem/1655

#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        
        if(max_heap.empty())
            max_heap.push(x);
        else if(max_heap.size() == min_heap.size())
            max_heap.push(x);
        else
            min_heap.push(x);
        
        if(!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
            int a = max_heap.top();
            int b = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            max_heap.push(b);
            min_heap.push(a);
        }
        
        cout << max_heap.top() << '\n';
    }
    
    return 0;
}
