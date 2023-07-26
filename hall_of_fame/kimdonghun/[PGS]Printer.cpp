#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int> > q;
    priority_queue<int> pq;
   
    for(int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()) {
        int curIndex = q.front().first;
        int curElement = q.front().second;
        
        q.pop();
        
        if(curElement == pq.top()) {
            pq.pop();
            answer++;
            
            if(curIndex == location) {
                break;
            }
        }
        else {
            q.push(make_pair(curIndex, curElement));
        }
    }

    return answer;
} 
