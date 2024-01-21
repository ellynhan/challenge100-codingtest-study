#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end());
    
    bool isFinish = false;
    int start = targets[0][0], end = targets[0][1]; // 이전 미사일 좌표
    for(int i = 0; i < targets.size(); i++){
        isFinish = false;
        int s = targets[i][0]; // 이번 좌표 시작
        int e = targets[i][1]; // 이번 좌표 끝

        // 더 짧은 범위가 있으면 갱신
        if(e < end) end = e;
        
        // 이전 좌표 사이에 없으면 (== 한 방 요격 불가능)
        if(s >= end) isFinish = true;
        
        // 정답이랑 좌표 갱신
        if(isFinish){
            answer++;
            start = s;
            end = e;
        }
        
        if(i == targets.size() - 1) answer++;
    }
    
    return answer;
}
