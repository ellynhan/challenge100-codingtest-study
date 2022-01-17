#include <bits/stdc++.h>

using namespace std;

double vectorSum(int N, bool visited[], vector<pair<int,int>> &points){
    pair<int,int> sum = {0, 0};
    for(int i = 0; i < N; i++){
        if(visited[i]){
            sum.first -= points[i].first;
            sum.second -= points[i].second;
        }
        else{
            sum.first += points[i].first;
            sum.second += points[i].second;
        }
    }
    return sqrt(pow(sum.first,2) + pow(sum.second,2));
}


void dfs(int now, int cnt, int N, bool visited[], vector<pair<int,int>> &points, double &result){
    if(cnt == N/2){
        result = min(result, vectorSum(N, visited, points));
        return;
    }
    for(int i = now; i < N; i++){
        visited[i] = true;
        dfs(i+1, cnt+1, N, visited, points, result);
        visited[i] = false;
    }
}


void input(int &N, vector<pair<int,int>> &points){
    int a, b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        points.push_back({a, b});
    }
}


int main(){
    int testCase, N;
    double result;
    vector<pair<int,int>> points;

    cin >> testCase;
    while(testCase--){
        bool visited[20]={false};
        points.clear();
        result = 1e6;

        input(N, points);
        dfs(0, 0, N, visited, points, result);
        printf("%.15lf\n", result);
    }
    return 0;
}
