#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int arr[10] = {0};

string solution(string X, string Y) {
    vector<int> tmp;
    string answer = "";
    for (int i = 0; i < X.size(); i++) {
        arr[X[i] - '0']++;
    }
    for (int i = 0; i < Y.size(); i++) {
        if (arr[Y[i] - '0'] != 0) {
            arr[Y[i] - '0']--;
            tmp.push_back(Y[i] - '0');
        } 
    }
    sort(tmp.begin(), tmp.end(), greater<int>());
    std::stringstream ss;
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        ss << *it;
    }

    if (ss.str()[0] == '0') {
        return "0";
    }
    return  ss.str() == "" ? "-1" : ss.str();
}