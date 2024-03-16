//
//  27888.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/5/24.
//

/*
 [Input]
 3
 Daredemo
 Daisuki
 original
 4
 U Daredemo kami
 U original ittkii,kami
 G kami,ittkii
 G kami
 [Output]
 1
 2
 */
// 시간복잡도: O(n ^ 5)
// 최악시간: 500,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/27888

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
int n, r;
string stationName, featureInput;
char op;
unordered_map<string, int> stationId;
vector<vector<string>> station;
unordered_map<string, int> cnt;

void generateCombinations(const vector<string>& elements, int K, vector<string>& result) {
    int N = int(elements.size());
    vector<int> v(N);
    fill(v.begin() + K, v.end(), 1);
    do {
        string ret = "";
        for (int i = 0; i < N; i++) {
            if(!v[i]) {
                ret += elements[i];
            }
        }
        result.push_back(ret);
    } while (next_permutation(v.begin(), v.end()));
}

vector<string> parseFeature(string featureInput) {
    vector<string> ret;
    stringstream ss(featureInput);
    string token;
    while(getline(ss, token, ',')) {
        ret.push_back(token);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

void updateStation(vector<string>& featureList) {
    for(int i = 1; i <= station[stationId[stationName]].size(); i++) {
        vector<string> combinations;
        generateCombinations(station[stationId[stationName]], i, combinations);
        for(string featureInput: combinations) {
            cnt[featureInput]--;
        }
    }
    for(int i = 1; i <= featureList.size(); i++) {
        vector<string> combinations;
        generateCombinations(featureList, i, combinations);
        for(string featureInput: combinations) {
            if(cnt.find(featureInput) == cnt.end())
                cnt[featureInput] = 0;
            cnt[featureInput]++;
        }
    }
    station[stationId[stationName]] = featureList;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> stationName;
        stationId[stationName] = i;
        station.push_back(vector<string>());
    }
    cin >> r;
    for(int i = 0; i < r; i++) {
        cin >> op;
        if(op == 'U') {
            cin >> stationName >> featureInput;
            vector<string> featureList = parseFeature(featureInput);
            updateStation(featureList);
        } else {
            cin >> featureInput;
            vector<string> featureList = parseFeature(featureInput);
            featureInput = "";
            for(string str: featureList)
                featureInput += str;
            cout << cnt[featureInput] << '\n';
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    solve();

	return 0;
}
