#include <iostream>
#include <string>
#include <vector>

using namespace std;

int row, column;
int idx_i, idx_j;

void init(vector<string> park){
    row = park.size();
    column = park[0].size();
    
    int i, j;
    for(i = 0; i<row; i++){
        for(j = 0; j<column; j++){
            if(park[i][j] == 'S'){
                idx_i = i;
                idx_j = j;
                return;
            }
        }
    }
}

void routing(vector<string> park, vector<string> routes){
    int len, i;
    for(auto route:routes){
        len = stoi(route.substr(2));
        if(route[0] == 'S' && idx_i + len < row){ 
            for(i=1; i<len+1; i++){
                if(park[idx_i + i][idx_j] == 'X') break;
            }
            if(i == len+1)
                idx_i += len;
        } else if(route[0] == 'W' && idx_j - len >= 0){ 
            for(i=1; i<len+1; i++){
                if(park[idx_i][idx_j - i] == 'X') break;
            }
            if(i == len+1)
                idx_j -= len;
        } else if(route[0] == 'N' && idx_i - len >= 0){ 
            for(i=1; i<len+1; i++){
                if(park[idx_i - i][idx_j] == 'X') break;
            }
            if(i == len+1)
                idx_i -= len;
        } else if(route[0] == 'E' && idx_j + len < column){ 
            for(i=1; i<len+1; i++){
                if(park[idx_i][idx_j + i] == 'X') break;
            }
            if(i == len+1)
                idx_j += len;
        } 
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    init(park);
    routing(park, routes);
    
    answer.push_back(idx_i);
    answer.push_back(idx_j);
    
    return answer;
}
