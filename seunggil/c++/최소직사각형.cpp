#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int horizontal = 0, vertical = 0;
    for(vector<int> iter : sizes){
        if(iter[1] > iter[0]){
            int temp = iter[0];
            iter[0] = iter[1];
            iter[1] = temp;
        }
        
        if(horizontal < iter[0])
            horizontal = iter[0];
        if(vertical < iter[1])
            vertical = iter[1];
        
    }
    int answer = horizontal * vertical;
    return answer;
}