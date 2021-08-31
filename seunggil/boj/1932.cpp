#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

    int n;
    vector<vector<int>> inputData;
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        inputData.push_back(vector<int>(i));

    cin >> inputData[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i+1; j++)
            cin >> inputData[i][j];

        inputData[i][0] += inputData[i-1][0];
        for (int j = 1; j < i; j++)
            inputData[i][j] += inputData[i-1][j-1] > inputData[i-1][j] ? inputData[i - 1][j - 1] : inputData[i - 1][j];
        inputData[i][i] += inputData[i-1][i-1];
    }
        

    //for (vector<int>& iter1 : inputData) {
    //    for (int iter2 : iter1)
    //        cout << iter2 << " ";
    //    cout << endl;
    //}

    cout << *max_element(inputData.back().begin(), inputData.back().end()) << endl;
    
    return 0;
}