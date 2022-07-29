#include<iostream>
#include<vector>

using namespace std;

struct Item {
    int weight;
    int value;
};
vector<Item> items;
int N, K;
int DP[101][100001];

void Input()
{
    cin >> N >> K;
    for(int i=0; i<N; i++)
    {
        int W, V;
        cin >> W >> V;
        items.push_back({W, V});
    }
}

void Solve()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=K; j++)
        {
            if(items[i-1].weight <= j)
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-items[i-1].weight] + items[i-1].value);
            else DP[i][j] = DP[i-1][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    Input();
    Solve();
    cout << DP[N][K];
}