#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> m;
    for(int i = 0; i < s.size(); i++){
        auto it = m.find(s[i]);
        if(it == m.end()){
            m.insert({s[i], 1});
        }
        else{
            it->second++;
        }
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second == 1){
            answer.push_back(it->first);
        }
    }
    return answer;
}
