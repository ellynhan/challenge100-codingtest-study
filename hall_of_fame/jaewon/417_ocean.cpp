class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        
        int n = heights.size();
        int m = heights[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int visited[200][200] = {0};
                visited[i][j] = 1;
                bool ocean[2] = {false, false};
                queue<pair<int, int>> q;
                q.push({i,j});
                while(!q.empty()){
                    if(ocean[0] && ocean[1]) break;
                    pair<int,int> curr = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int Y = dy[k] + curr.first;
                        int X = dx[k] + curr.second;
                        if(Y < 0 || X < 0){
                            ocean[0] = true;
                            continue;
                        }
                        if(Y >= n || X >= m){
                            ocean[1] = true;
                            continue;
                        }
                        if(heights[Y][X] <= heights[curr.first][curr.second] && visited[Y][X] == 0){
                            q.push({Y,X});
                            visited[Y][X] = 1;
                        }
                    }
                }
                if(ocean[0] && ocean[1]){
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    answer.push_back(tmp);
                }
            }
        }
        return answer;
    }
};