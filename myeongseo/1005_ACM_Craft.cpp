#include <bits/stdc++.h>

using namespace std;

int calTime(vector<int> &times, map<int, vector<int>> &rule, int wantBuilding, map<int, int> &calc) {
    int biggest = 0;
    if(calc.find(wantBuilding) != calc.end()) return calc[wantBuilding];

    for(auto b : rule[wantBuilding]) {
        if(calc.find(b) == calc.end()) calTime(times, rule, b, calc);
        if(calc[b] > biggest) biggest = calc[b];
    }

    calc[wantBuilding] = biggest + times[wantBuilding-1];
    return calc[wantBuilding];
}


void output(vector<int> &times, map<int, vector<int>> &rule) {
    int wantBuilding;
    cin >> wantBuilding;
    map<int, int> calc;

    cout << calTime(times, rule, wantBuilding, calc) <<endl;
}


void input(vector<int> &times, map<int, vector<int>> &rule) {
    int N, K;
    int time, before, after;

        cin >> N;
        cin >> K;
        while(N--) {
            cin >> time;
            times.push_back(time);
        }
        while(K--) {
            cin >> before;
            cin >> after;
            rule[after].push_back(before);
        }
}


int main() {
    vector<int> times;
    map<int, vector<int>> rule;
    vector<int> least;
    int T;

    cin >>T;
    while(T--) {
        times.clear();
        rule.clear();
        input(times, rule);
        output(times, rule);
    }
    return 0;
}
