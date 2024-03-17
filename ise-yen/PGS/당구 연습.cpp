#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int pow_dis(int sx, int sy, int bx, int by){
    return pow(abs(sy-by), 2) + pow(abs(sx-bx), 2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i = 0; i < balls.size(); i++){
        int bx = balls[i][0];
        int by = balls[i][1];
        
        vector<pair<int, int>> start = {{startX, -startY}, {-startX, startY}, {startX, n+n-startY}, {m+m-startX, startY}}; // y=0 대칭, x=0 대칭, y=n 대칭, x=m 대칭
        vector<int> v;
        if(startX == bx){
            if(startY > by) v.push_back(pow((n-startY + n-by), 2));
            else v.push_back(pow((startY + by), 2));
        }
        else if(startY == by){
            if(startX > bx) v.push_back(pow((m-startX + m-bx), 2));
            else v.push_back(pow((startX + bx), 2));
        }
        for(int s = 0; s < start.size(); s++){
            if(startX == bx){
                if(s == 0 || s == 2) continue;
            }
            else if(startY == by){
                if(s == 1 || s == 3) continue;
            }
            int sx = start[s].first;
            int sy = start[s].second;
            
            v.push_back(pow_dis(sx, sy, bx, by));
        }
        sort(v.begin(), v.end());
        
        answer.push_back(v[0]);
    }
    return answer;
}
