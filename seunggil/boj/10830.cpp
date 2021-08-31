#include <vector>
#include <map>
#include <iostream>

using namespace std;

int N;
long long B;

vector<vector<int>> matrixMultiple(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    vector<vector<int>> result(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int z = 0; z < N; z++)
                result[i][z] += (a[i][j] * b[j][z]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][j] %= 1000;

    return result;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;

    vector<vector<int>> inputData(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> inputData[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inputData[i][j] %= 1000;

    map<long long, vector<vector<int>>> result;

    long long nowSize = 1;
    result[1] = inputData;

    while (nowSize != B) {
        map<long long, vector<vector<int>>>::iterator iter = --result.upper_bound(B - nowSize);
        result[nowSize + iter->first] = matrixMultiple(result[nowSize], result[iter->first]);
        nowSize += iter->first;
    }
    
    vector<vector<int>> ans = result[nowSize];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}