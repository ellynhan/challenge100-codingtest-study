#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
/*
ax+by+f = 0
cx+dy+e = 0
x = bf-ed/ad-bc
y = ec-af/ad-bc
*/
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    map<pair<int,int>,int> m;
    int xMinMax[2]={INT32_MAX,-INT32_MAX};
    int yMinMax[2]={INT32_MAX,-INT32_MAX};
    for(int i=0; i<line.size()-1; i++){
        for(int j=i+1; j<line.size(); j++){
            if(line[i][0]*line[j][1]-line[j][0]*line[i][1]==0)continue;
            double x = (double)(line[i][1]*line[j][2]-line[i][2]*line[j][1])/(line[i][0]*line[j][1]-line[j][0]*line[i][1]);
            double y = (double)(line[i][2]*line[j][0]-line[i][0]*line[j][2])/(line[i][0]*line[j][1]-line[j][0]*line[i][1]);
            if(x-int(x)!=0 || y-int(y)!=0)continue;
            m[{x,-y}]=1;
            xMinMax[0] = min(xMinMax[0],(int)x);
            xMinMax[1] = max(xMinMax[1],(int)x);
            yMinMax[0] = min(yMinMax[0],-(int)y);
            yMinMax[1] = max(yMinMax[1],-(int)y);
        }
    }
    for(long long i=yMinMax[0]; i<=yMinMax[1]; i++){
        string s="";
        for(long long j=xMinMax[0]; j<=xMinMax[1]; j++){
            if(m.count({j,i})>0){
                s+="*";
            }else{
                s+=".";
            }
        }
        answer.push_back(s);
    }
    return answer;
}
