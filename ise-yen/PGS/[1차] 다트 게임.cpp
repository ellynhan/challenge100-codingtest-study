#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


int makeScore(queue<char> *q){
    int score{};
    while(!q->empty()){
        score += q->front() - '0';
        q->pop();
        if(q->empty()) break;
        score *= 10;
    }
    return score;
}

int solution(string dartResult) {
    int answer = 0;
    queue<char> q;
    vector<int> v;
    int pos = -1;
    for(int i = 0; i < dartResult.size(); i++){
        char c = dartResult[i];
        if(c >= '0' && c <= '9') q.push(c);
        else if(c == 'S' || c == 'D' || c == 'T'){
            pos++;
            int score = makeScore(&q);
            if(c == 'D') score = pow(score, 2);
            else if(c == 'T') score = pow(score, 3);
            v.push_back(score);
        }
        else if(c == '*'){
            for(int p = pos, cnt = 0; p >= 0; p--){
                if(cnt == 2) break;
                v[p] *= 2;
                cnt++;
            }
        }
        else if(c == '#') v[pos] *= -1;
    }
    
    for(int n : v) answer += n;
    return answer;
}
