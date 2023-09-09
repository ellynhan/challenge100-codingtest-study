#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int,int>> items;

int dp[10001][2020];

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    items.emplace_back(0, 0);

    for (int i = 0; i < N; ++i) {
        int w, c, k;
        cin >> w >> c >> k;

        for(int j = k; j > 0; j >>=1){
            int part = j - (j >> 1);
            items.emplace_back(w*part, c*part);
        }
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j < items.size(); ++j) {
            dp[i][j] = dp[i][j-1];
            
            if(i >= items[j].first) {
                dp[i][j] = max(dp[i][j], dp[i - items[j].first][j - 1] + items[j].second);
            }
        }
    }

    cout << dp[M][items.size()-1];
    
    return 0;
}

