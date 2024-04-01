#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> pq;
    for(int s : scoville) pq.push(-s);
    
    while(!pq.empty()){
        if(-pq.top() >= K) break;
        if(pq.size() == 1){
            answer = -1;
            break;
        }
        answer++; // 섞기
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
    }
    return answer;
}
