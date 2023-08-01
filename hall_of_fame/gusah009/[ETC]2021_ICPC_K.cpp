#include <iostream>
#include <queue>

#define INF 198765432

using namespace std;

int M, N, K;
int answer = -1;
priority_queue<int> A[100001];
bool isAllEmpty = false;

void input()
{
    cin >> M >> N >> K;
    int x, y;
    for (int k = 0; k < K; k++) {
        cin >> x >> y;
        A[x].push(-y);
    }
}

void solve()
{
    while (!isAllEmpty) {
        int numFlag = INF;
        isAllEmpty = true;
        for (int m = M; m > 0; m--) {
            if (!A[m].empty()) {
                isAllEmpty = false;
                if (numFlag >= -A[m].top()) {
                    int tmp = -A[m].top();
                    while(!A[m].empty() && numFlag >= -A[m].top()) {
                        // cout << A[m].top() << ' ';
                        A[m].pop();
                    }
                    // cout << '\n';
                    numFlag = tmp;
                }
            }
        }
        answer++;
    }
}

void print()
{
    cout << answer << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    input();
    solve();
    print();
}