#include <iostream>
#include <map>
#include <utility>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {

    int city;
    int bus;
    cin >> city >> bus;

    vector<vector<int>> inputData(city, vector<int>(city,INT32_MAX));
    
    while (bus-- > 0) {
        int start, end, cost;
        cin >> start >> end >> cost;
        start--, end--;

        if(inputData[start][end] > cost)
            inputData[start][end] = cost;
    }

    int start, end;
    cin >> start >> end;
    start--, end--;
    map<int, int> result;
    for (int i = 0; i < city; i++)
        result[i] = inputData[start][i];
    result[start] = 0; // 자기 자신은 0
    result.erase(start);
    vector<int> cost(city);

    while (!result.empty()) {
        map<int, int>::iterator iter = min_element(result.begin(), result.end(),
            [](const pair<int,int>& it1, const pair<int, int>& it2) {
                return it1.second < it2.second;
            });

        for (pair<const int, int>& mapIter : result)
            if (inputData[iter->first][mapIter.first] != INT32_MAX
                && mapIter.second > iter->second + inputData[iter->first][mapIter.first])
                mapIter.second = iter->second + inputData[iter->first][mapIter.first];
 
        cost[iter->first] = iter->second;
        result.erase(iter);
    }

    cout << cost[end] << endl;

    return 0;
}