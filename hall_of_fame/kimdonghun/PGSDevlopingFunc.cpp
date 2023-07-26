#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;
    

    
    for(int i = progresses.size() - 1; i >= 0; i--) {
        s.push( ceil((double)(100 - progresses[i]) / speeds[i]));
    }
    
    int curMax = s.top();
    int curCnt = 1;
    
    cout << curMax << " ";
    s.pop();
    
    
    for(int i = progresses.size() - 2; i >= 0; i--) {
        cout << s.top() << " ";
        
        if(s.top() > curMax) {
            answer.push_back(curCnt);
            curMax = s.top(); 
            curCnt = 0;
        }
        
        curCnt++;
        
        if(i == 0) {
            answer.push_back(curCnt);
        }

        s.pop();
    }
    
    return answer;
}
