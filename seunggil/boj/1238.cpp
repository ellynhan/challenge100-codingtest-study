#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::vector;
using std::endl;

constexpr int INF = 200000;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int town, road, student;
    cin >> town >> road >> student;

    vector<vector<int>> inputData(town+1, vector<int>(town+1, INF));

    for(int i = 0; i < road; i++){
        int from, to, length;
        cin >> from >> to >> length;
        inputData[from][to] = length;
    }
    for (int i = 1; i <= town; i++)
        inputData[i][i] = 0;

    for (int i = 1; i <= town; i++)
        for (int j = 1; j <= town; j++)
            for (int k = 1; k <= town; k++) {
                int length = inputData[j][i] + inputData[i][k];
                if (inputData[j][k] > length)
                    inputData[j][k] = length;
            }



    int answer = 0;

    for (int i = 1; i <= town; i++) {
        int length = inputData[i][student] + inputData[student][i];
        if (answer < length)
            answer = length;
    }

    cout << answer;

    //for (int i = 1; i <= town; i++) {
    //    for (int j = 1; j <= town; j++) {
    //        cout << inputData[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    return 0;
}