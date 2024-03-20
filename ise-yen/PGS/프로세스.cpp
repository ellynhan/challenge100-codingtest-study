#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q; // 우선순위, 번호
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i});
    }
    
    while(!q.empty()){
        int pr = q.front().first;
        int num = q.front().second;
        q.pop();
        
        bool isPr = true; // 지금 pr이 가장 높은지
        for(int i = 0; i < priorities.size(); i++){
            if(priorities[i] > pr){
                isPr = false;
                break;
            }
        }
        if(isPr){
            priorities[num] = -1;
            answer++;
            if(location == num) return answer;
        }
        else{
            q.push({pr, num});
        }
    }
    
    return answer;
}
