#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 0 : -> 
// 1 : v
// 2 : <-
// 3 : ㅅ

int row, column;
class gridInfo{
    public:
    char type;
    bool dir[4] = {false,false,false,false}; //각각 0123
};



vector<int> solution(vector<string> grid) {
    vector<vector<gridInfo>> cycle(grid.size(), vector<gridInfo>(grid[0].size()));
    row = grid.size();
    column = grid[0].size();
    
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j<grid[i].size(); j++)
            cycle[i][j].type = grid[i][j];
    
    
    vector<int> answer;
    
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j< grid[i].size(); j++)
            for(int z = 0; z < 4; z++){
                int length = 0;
                int x = i;
                int y = j;
                int dir = z;
                
                while(cycle[x][y].dir[dir] == false){
                    cycle[x][y].dir[dir] = true;
                    length++;
                    
                    switch(dir){
                        case 0: // 오른쪽으로
                            y = (y == column -1) ? 0 : y + 1;
                            break;
                        case 1: // 아래
                            x = (x == row -1) ? 0 : x + 1;
                            break;
                        case 2: // 왼쪽
                            y = (y == 0) ? column -1 : y - 1;
                            break;
                        case 3: // 위
                            x = (x == 0) ? row -1 : x - 1;
                    }
                    
                    switch (cycle[x][y].type){
                    case 'S':
                        break;
                    case 'L':
                        dir = dir == 0 ? 3 : dir-1;
                        break;
                    case 'R':
                        dir = dir == 3 ? 0 : dir+1;
                        break;
                    }
                    
                }
                if(length != 0)
                    answer.push_back(length);
            }   
    
    // for(int i = 0; i < grid.size(); i++){
    //     for(int j = 0; j<grid[i].size(); j++){
    //         cout << cycle[i][j].type << " ";
    //     }cout << endl;
    // }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}