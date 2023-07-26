#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//1. 퍼즐 조각 분리 -> 시작 좌표를 0,0으로 시작해서 이어지는 대로 좌표를 구하면 될 것 같은데. -> bfs로 하면 될 것 같다.
//2. 퍼즐 조각 회전
//3. 퍼즐 조각 채우기
//4. dfs 추정
vector<vector<pair<int, int>> > parts;
vector<vector<pair<int, int>> > blanks;
int used[50]={0};
int xx[4] = {0,0,-1,1};
int yy[4] = {-1,1,0,0};
//minX = 0, minY = 0

bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.first<b.first){
        return true;
    }else if(a.first==b.first){
        return a.second<b.second;
    }else{
        return false;
    }
}

void rotatePartRight90(vector<pair<int, int>>& part){
    int xMin=0, yMin=0;
    for(int i=0; i<part.size(); i++){
        part[i] = {-part[i].second, part[i].first};
        xMin = min(part[i].second, xMin);
        yMin = min(part[i].first,yMin);
    }
    if(xMin<0||yMin<0){
        for(int i=0; i<part.size(); i++){
            part[i] = {part[i].first-yMin,part[i].second-xMin};
        }
    }
    sort(part.begin(),part.end(),cmp);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int size = game_board.size();
    
    //find Parts
    queue<pair<int, int>> q;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(table[i][j]==1){
                q.push({i,j});
                vector<pair<int,int>> part;
                part.push_back({0,0});
                table[i][j]=0;
                int xMin=0;
                int yMin=0;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int Y = y+yy[k];
                        int X = x+xx[k];
                        if(X<0||Y<0||X>=size||Y>=size)continue;
                        if(table[Y][X]==1){
                            q.push({Y,X});
                            part.push_back({Y-i,X-j});
                            xMin = min(xMin,X-j);
                            yMin = min(yMin,Y-i);
                            table[Y][X]=0;
                        }
                    }
                }
                if(xMin<0||yMin<0){
                    for(int k=0; k<part.size(); k++){
                        part[k] = {part[k].first-yMin,part[k].second-xMin};
                    }
                }
                sort(part.begin(), part.end(), cmp);
                parts.push_back(part);
            }
        }    
    }
    //findpart done
    
    //find blanks
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(game_board[i][j]==0){
                q.push({i,j});
                vector<pair<int,int>> blank;
                blank.push_back({0,0});
                game_board[i][j]=1;
                int xMin = 0;
                int yMin = 0;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int Y = y+yy[k];
                        int X = x+xx[k];
                        if(X<0||Y<0||X>=size||Y>=size)continue;
                        if(game_board[Y][X]==0){
                            q.push({Y,X});
                            blank.push_back({Y-i,X-j});
                            game_board[Y][X]=1;
                            xMin = min(xMin, X-j);
                            yMin = min(yMin, Y-i);
                        }
                    }
                }
                if(xMin<0||yMin<0){
                    for(int k=0; k<blank.size(); k++){
                        blank[k] = {blank[k].first-yMin,blank[k].second-xMin};
                    }
                }
                sort(blank.begin(),blank.end(),cmp);
                blanks.push_back(blank);
            }
        }
    }
    //find blanks done

   vector<int> usedPart(parts.size(),0);
    //start to find fit part & blank
    for(int i=0; i<blanks.size(); i++){
        int currBlankSize = blanks[i].size();
        for(int j=0; j<parts.size(); j++){
            if(usedPart[j]==1)continue;
            if(currBlankSize == parts[j].size()){
                if(blanks[i] == parts[j]){
                    usedPart[j]=1;
                    break;
                }else{
                    int isFit = 0;
                    for(int k=0; k<3; k++){
                        rotatePartRight90(parts[j]);
                        if(blanks[i] == parts[j]){
                            usedPart[j]=1;
                            isFit = 1;
                            break;
                        }
                    }
                    if(isFit==1){
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<parts.size(); i++){
        if(usedPart[i]==1){
            answer+=parts[i].size();
        }
    }
    return answer;
}
