#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m; // 문자, 몇번 눌러야하는지
    for(int i = 0; i < keymap.size(); i++){
        for(int j = 0; j < keymap[i].length(); j++){
            char c = keymap[i][j];
            auto it = m.find(c);
            if(it == m.end()){
                m.insert({c, j+1}); // 횟수는 j+1인거 주의
            }
            else{
                m[c] = m[c] < j+1 ? m[c] : j+1;
            }
        }
    }

    for(int i = 0; i < targets.size(); i++){
        int cnt{};
        for(int j = 0; j < targets[i].length(); j++){
            char c = targets[i][j];
            auto it = m.find(c);
            if(it == m.end()){
                cnt = -1;
                break;
            }
            else{
                cnt += m[c];
            }
        }
        answer.push_back(cnt);
    }
    
    
    return answer;
}
