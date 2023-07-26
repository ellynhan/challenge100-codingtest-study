#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int row, column;
int startX, startY;
int visited[100][100] = {0,};
int idxX[] = {1, -1, 0, 0};
int idxY[] = {0, 0, 1, -1};


int routing(vector<string> board, int x, int y){
    queue<int> posX; posX.push(x);
    queue<int> posY; posY.push(y);
    queue<int> count; count.push(0);
    
    int result = INT32_MAX;
    int currX, currY, currCnt, i, tmp;
    while(!posX.empty()){
        currX = posX.front(); posX.pop();
        currY = posY.front(); posY.pop();
        currCnt = count.front(); count.pop();
        
        if(visited[currX][currY] != 0) continue;
        else visited[currX][currY] = 1;
        
        if(board[currX][currY] == 'G'){
            result = min(result, currCnt);
            continue;
        }
        
        for(i=0; i<4; i++){
            tmp = idxX[i] + idxY[i];
            if(idxY[i] == 0){
                if((currX + tmp < row && currX + tmp >= 0) 
                    && board[currX + tmp][currY] != 'D'){
                    
                    while((currX + tmp < row && currX + tmp >= 0) 
                           && board[currX + tmp][currY] != 'D') 
                        tmp += idxX[i] + idxY[i];
                    tmp -= idxX[i] + idxY[i];
                    
                    posX.push(currX+tmp);
                    posY.push(currY);
                    count.push(currCnt + 1);
                }
            } else {
                if((currY + tmp < column && currY + tmp >= 0) 
                    && board[currX][currY + tmp] != 'D'){
                    
                    while((currY + tmp < column && currY + tmp >= 0) 
                           && board[currX][currY + tmp] != 'D') 
                        tmp += idxX[i] + idxY[i];
                    tmp -= idxX[i] + idxY[i];
                    
                    posX.push(currX);
                    posY.push(currY+tmp);
                    count.push(currCnt + 1);
                }
            }
        }
        
    }
    
    if(result == INT32_MAX) return -1;
    return result;
}

void init(vector<string> board){
    row = board.size();
    column = board[0].size();
    
    int i, j;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(board[i][j] == 'R'){
                startX = i;
                startY = j;
                return;
            }
        }
    }
}

int solution(vector<string> board) {
    
    init(board);
    int answer = routing(board, startX, startY);
    
    return answer;
}
