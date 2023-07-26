#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string s){
    if(s == "") return "YES";
    
    if(s[0] == '0'){
        if(s[1] != '1') return "NO";
        return solution(s.substr(2));
    } else {
        int idx = s.find('1', 1);
        if(idx < 3) return "NO";
        string answer;
        while(s[idx] == '1'){
            answer = solution(s.substr(idx+1));
            if(answer == "YES") return "YES";
            idx++;
        }
        return answer;
    }
}

int main(){
    int N; cin >> N;
    string prop;
    vector<string> answer;
    while(N--){
        cin >> prop;
        answer.push_back(solution(prop));
    }
    for(string ans:answer) cout << ans << "\n";

    return 0;
}
