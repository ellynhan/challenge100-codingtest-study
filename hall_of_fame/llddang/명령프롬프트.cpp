#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;
    vector<string> store;

    for(int i=0; i<N; i++){
        string tmp; cin >> tmp;
        store.push_back(tmp);
    }

    string answer = store[0];

    for(int i=1; i<N; i++){
        for(int j=0; j<answer.size(); j++){
            if(answer[j] != store[i][j]){
                answer.replace(j, 1, "?");
            }
        }
    }

    cout << answer;
}
