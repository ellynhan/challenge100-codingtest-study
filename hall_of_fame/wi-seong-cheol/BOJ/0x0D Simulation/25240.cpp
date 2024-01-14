//
//  25240.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/5/24.
//

/*
 [Input]
 3 2
 cho
 gahui alpa
 mysql
 namahage 754 cho alpa
 dochida 644 cho cho
 3
 cho namahage X
 gahui namahage W
 mysql namahage X
 [Output]
 1
 0
 0
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Gold 3
// Timer: 1h 30m
// Url: https://www.acmicpc.net/problem/25240

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <tuple>
#include <algorithm>

using namespace std;
int u, f, q;
unordered_map<int, string> auth = {{0, "000"}, {1, "001"}, {2, "010"}, {3, "011"}, {4, "100"}, {5, "101"}, {6, "110"}, {7, "111"}};
unordered_map<char, int> op2auth = {{'R', 0}, {'W', 1}, {'X', 2}};
unordered_map<string, int> groupId;
unordered_map<string, int> fileId;
vector<vector<string>> group;
vector<tuple<string, string, string>> file;

void inputUser() {
    cin.ignore();
    for(int i = 0; i < u; i++) {
        string input;
        getline(cin, input);

        stringstream ss1(input);
        vector<string> info;

        while(ss1 >> input) {
            info.push_back(input);
        }

        string userName = info[0];

        if(info.size() > 1) {
            stringstream ss2(info[1]);
            string groupName;

            while(getline(ss2, groupName, ',')) {
                if(groupId.find(groupName) == groupId.end()) {
                    groupId[groupName] = int(group.size());
                    group.push_back(vector<string>());
                }
                group[groupId[groupName]].push_back(userName);
            }
        }
    }
}

void inputFile() {
    for(int i = 0; i < f; i++) {
        string fileName, authInfo, owner, groupInfo;
        cin >> fileName >> authInfo >> owner >> groupInfo;
        fileId[fileName] = i;
        file.push_back(make_tuple(authInfo, owner, groupInfo));
    }
}

bool isAuth(string userName, string fileName, char op) {
    if(fileId.find(fileName) == fileId.end()) {
        return false;
    }
    int opInt = op2auth[op];

    string authInfo, owner, groupInfo;
    tie(authInfo, owner, groupInfo) = file[fileId[fileName]];

    // owner 권한 확인
    if(owner == userName) {
        if(auth[authInfo[0] - '0'][opInt] == '1') {
            return true;
        }
    }

    if(groupInfo == userName) { // group In 권한 확인
        if(auth[authInfo[1] - '0'][opInt] == '1') {
            return true;
        }
    }

    if(groupId.find(groupInfo) == groupId.end()) {
        return auth[authInfo[2] - '0'][opInt] == '1';
    }

    auto findGroup = group[groupId[groupInfo]];

    if(find(findGroup.begin(), findGroup.end(), userName) != findGroup.end()) {
        if(auth[authInfo[1] - '0'][opInt] == '1') {
            return true;
        }
    } else { // group Out 권한 확인
        if(auth[authInfo[2] - '0'][opInt] == '1') {
            return true;
        }
    }

    return false;
}

void inputQuery() {
    cin >> q;
    for(int i = 0; i < q; i++) {
        string userName, fileName;
        char op;
        cin >> userName >> fileName >> op;
        cout << isAuth(userName, fileName, op) << '\n';
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> u >> f;
    inputUser();
    inputFile();
    inputQuery();

	return 0;
}
