#include <string>
#include <vector>
#include <map>
using namespace std;
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    map<pair<int,int>,int> m;
    int xMinMax[2]={INT32_MAX,-INT32_MAX};
    int yMinMax[2]={INT32_MAX,-INT32_MAX};
    for(int i=0; i<line.size()-1; i++){
        for(int j=i+1; j<line.size(); j++){
            long long a = line[i][0];
            long long b = line[i][1];
            long long c = line[j][0];
            long long d = line[j][1];
            long long e = line[i][2];
            long long f = line[j][2];
            long long adbc = a*d-b*c;
            if(adbc==0)continue;
            long long bfed = b*f-e*d;
            long long ecaf = e*c-a*f;
            if(bfed%adbc!=0 || ecaf%adbc!=0)continue;
            int x = bfed/adbc;
            int y = ecaf/adbc;
            m[{x,-y}]=1;
            xMinMax[0] = min(xMinMax[0],x);
            xMinMax[1] = max(xMinMax[1],x);
            yMinMax[0] = min(yMinMax[0],-y);
            yMinMax[1] = max(yMinMax[1],-y);
        }
    }
    for(int i=yMinMax[0]; i<=yMinMax[1]; i++){
        string s="";
        for(int j=xMinMax[0]; j<=xMinMax[1]; j++){
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
