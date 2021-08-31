#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

vector<int> solution(string s) {
    s = s.substr(1, s.length() - 2);

    vector<set<int>> inputData;
    set<int> smallSet;
    string in;
    for (char sIter : s)
        switch (sIter) {
        case '{':
            in = "";
            smallSet.clear();
            break;
        case ',':
            smallSet.insert(stoi(in));
            in = "";
            break;
        case '}':
            smallSet.insert(stoi(in));
            inputData.push_back(smallSet);
            break;
        default:
            in += sIter;
            break;
        }


    sort(inputData.begin(), inputData.end(), [](const set<int>& A, const set<int>& B) {
        return A.size() < B.size();
        });

    vector<int> answer;
    for (int i = inputData.size() - 1; i > 0; i--) {
        for (int iter : inputData[i])
            if (inputData[i - 1].count(iter))
                inputData[i].erase(iter);

        assert(inputData[i].size() == 1);

        answer.push_back(*inputData[i].begin());
    }
    answer.push_back(*inputData[0].begin());
    reverse(answer.begin(), answer.end());
    // for(set<int> iter : inputData){
    //     for(int iter2 : iter)
    //         cout << iter2 << " ";
    //     cout << endl;
    // }


    return answer;
}