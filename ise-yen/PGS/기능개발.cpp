#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> finish;
    for(int i = 0; i < progresses.size(); i++){
        int t = 100 - progresses[i];
        if(t % speeds[i] == 0) finish.push(t / speeds[i]);
        else finish.push(t / speeds[i] + 1);
    }
    
    int cnt{}, f = -1;
    while(!finish.empty()){
        f = finish.front() > f ? finish.front() : f;
        finish.pop();
        cnt++;
        if(finish.front() > f){
            answer.push_back(cnt);
            cnt = 0;
            f = finish.front();
        }
    }
    if(cnt > 0) answer.push_back(cnt);
    return answer;
}
