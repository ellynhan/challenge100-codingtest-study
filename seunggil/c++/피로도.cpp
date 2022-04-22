#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool used[10];
pair<int, int> result[10];
int dungeonsSize;
int user;
int answer = 0;

int isVisitable() {
    int score = user;
    int count = 0;
    // for(int i = 0; i < dungeonsSize; i++){
    //     cout << result[i].first << ' ' << result[i].second << ' ';
    // }cout << endl;

    for (int i = 0; i < dungeonsSize; i++) {
        if (score < result[i].first)
            return count;
        score -= result[i].second;
        count++;
        if (score < 0)
            return count - 1;
    }
    return count;
}

void permutation(int count, const vector<vector<int>>& arr, int depth = 0) {
    if (count == arr.size()) {
        answer = max(isVisitable(), answer);
        return;
    }
    if (depth == arr.size())
        return;
    for (int i = 0; i < arr.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            result[count] = { arr[i][0],arr[i][1] };
            permutation(count + 1, arr, depth + 1);
            used[i] = false;
            permutation(count, arr, depth + 1);
        }
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    // for(vector<int>& iter : dungeons){
    //     for(int iter2: iter)
    //         cout << iter2 << ' ';
    //     cout << endl;
    // }
    user = k;
    dungeonsSize = dungeons.size();
    permutation(0, dungeons);
    return answer;
}