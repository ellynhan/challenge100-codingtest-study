#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int l = 0; l < commands.size(); l++){
        vector<int> c = commands[l];
        int i = c[0] - 1;
        int j = c[1] - 1;
        int k = c[2] - 1;
        
        vector<int> v;
        while(i <= j){
            v.push_back(array[i]);
            i++;
        }
        
        sort(v.begin(), v.end());
        answer.push_back(v[k]);
    }
    return answer;
}
