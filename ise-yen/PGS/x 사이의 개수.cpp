#include <string>
#include <vector>

using namespace std;

vector<int> solution(string str) {
    vector<int> answer;
    
    int cnt{};
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'x'){
            answer.push_back(cnt);
            cnt = 0;
        }
        else cnt++;
    }
    
    answer.push_back(cnt);

    return answer;
}
