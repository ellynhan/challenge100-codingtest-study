#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v;
    for(int i = 0; i <= n; i++){
        v.push_back(1);
    }
    
    for(int i = 0; i < reserve.size(); i++) v[reserve[i]]++;
    for(int i = 0; i < lost.size(); i++) v[lost[i]]--;
    
    for(int i = 1; i <= n; i++){
        if(v[i] == 0){
            if(i != 1 && v[i-1] > 1) {
                v[i-1]--;
                v[i]++;
            }
            else if(i != n && v[i+1] > 1){
                v[i+1]--;
                v[i]++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(v[i] > 0) answer++;
    }
    return answer;
}
