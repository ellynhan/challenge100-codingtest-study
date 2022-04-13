#include <iostream>
#include <vector>

using namespace std;
int result[51];

int main()
{
    int N;
    vector<pair<int,int>> v;
    cin >> N;
    
    for(int i=0; i<N; i++){
        int w, h;
        cin >> w >> h;
        v.push_back({w, h});
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i != j){
                if(v[i].first < v[j].first && v[i].second < v[j].second)
                    result[i]++;
            }
        }
    }
    
    for(int i=0; i<N; i++) cout << result[i]+1 << ' ';
}
