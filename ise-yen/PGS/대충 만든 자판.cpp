#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findMinPos(vector<string> *keymap, char target){
    int max = 10001;
    int min = max;

    for(int i = 0; i < keymap->size(); i++){
        auto it = keymap->at(i).find(target);
        
        if(it == keymap->at(i).size()) continue; // 다른 키맵에서 대상 찾기
        else{
            if(min > it) min = it+1; // 위치 갱신
            continue; // 다른 키맵에서도 대상 찾기
        }
    }
    
    if(min == max) return -1;
    return min;
}


vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i = 0; i < targets.size(); i++){
        int ans{};
        for(int j = 0; j < targets[i].size(); j++){
            char word = targets[i][j]; // 탐색할 철자
            
            if(findMinPos(&keymap, word) == -1) { // word를 찾을 수 없다면
                ans = -1;
                break; // 다음 문자열로
            }
            else ans += findMinPos(&keymap, word); // word 찾았으면 위치값 추가
        }
        
        answer.push_back(ans);
    }
    return answer;
}
