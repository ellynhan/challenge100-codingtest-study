#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int arr[58]{};
    fill(arr, arr+sizeof(arr)/sizeof(int), -1);

    for(int i = 0; i < s.length(); i++){
        int pos = s[i]-'A';
        if(arr[pos] == -1){
            answer.push_back(arr[pos]);
        }
        else{
            answer.push_back(i-arr[pos]);
        }
        arr[pos] = i; // 위치 갱신
    }
    return answer;
}
