#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    vector<int> people(n, 0);
    vector<string> m[26];
    char last;
    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        int st = word[0]-'a';
        people[i % n]++; // 차례 갱신

        bool flag = false;
        auto it = find(m[st].begin(), m[st].end(), word);
        if(it != m[st].end()) flag = true;
        // 탈락 조건
        if(i> 0 && (last != word[0] || flag)){
            answer[0] = i % n + 1;
            answer[1] = people[i % n];
            break;
        }
        else{
            m[st].push_back(word);
            last = word[word.length()-1]; // 마지막 글자 갱신
        }
    }
    return answer;
}
