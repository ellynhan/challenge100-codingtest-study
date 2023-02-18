#include <string>
#include <vector>
#include <iostream>
#define MAX_INDEX 10
using namespace std;

int max_diffrence;
vector<int> answer;
vector<int> ryan(MAX_INDEX + 1);
vector<int> apeach;

bool isNotPromise(vector<int> vecA, vector<int> vecB) {
    for(int i = MAX_INDEX; i >= 0; i--) {
        if(vecA[i] < vecB[i]) return true;
        else if (vecA[i] > vecB[i]) return false;
    }
}

void dfs(int index, int leftArrows, int apeachScore, int ryanScore){
    if(leftArrows == 0 || index == MAX_INDEX + 1){
        int curr_diffrence = ryanScore - apeachScore;

        if(curr_diffrence <= 0) return;
        if(max_diffrence <= curr_diffrence){
            ryan[MAX_INDEX] += leftArrows;
            if(max_diffrence == curr_diffrence && isNotPromise(ryan, answer)) return;
            answer = ryan;
            max_diffrence = curr_diffrence;
            ryan[MAX_INDEX] -= leftArrows;
        }
        return;
    }    

    if(apeach[index] < leftArrows){
        ryan[index] = apeach[index] + 1;
        
        if(apeach[index] > 0)
            apeachScore = apeachScore - MAX_INDEX + index;
        
        dfs(index + 1, leftArrows - apeach[index] - 1, apeachScore, ryanScore + 10 - index);
        
        if(apeach[index] > 0)
            apeachScore = apeachScore + MAX_INDEX - index;
        
        ryan[index] = 0;
    }
    
    dfs(index + 1, leftArrows, apeachScore, ryanScore);
}

vector<int> solution(int n, vector<int> info) {
    int apeachScore = 0;
    apeach = info;
    
    for(int i=0; i<info.size(); i++){
        if(info[i] > 0) apeachScore += (MAX_INDEX - i);
    }

    dfs(0 , n, apeachScore, 0);
    
    if(answer.empty() || max_diffrence == 0) {
        answer.push_back(-1);
    };
    
    return answer;
}