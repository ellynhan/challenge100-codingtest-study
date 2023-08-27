#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
vector<int> arr_index;
vector<int> num;
vector<int> before;

vector<int> answers;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    
    num.resize(n);
    before.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        
        if (i == 0) {
            arr.push_back(num[i]);
            before.at(i) = -1;
            arr_index.push_back(i);
        }

        if (arr.back() < num[i]) {
            arr.push_back(num[i]);
            before.at(i) = arr_index.back();
            arr_index.push_back(i);
        } else {
            auto iter = lower_bound(arr.begin(), arr.end(), num[i]);
            *iter = num[i];
            
            int now_index = iter - arr.begin();
            
            if (now_index > 0)
                before.at(i) = arr_index.at(now_index -1);
            else
                before.at(i) = -1;
            
            arr_index.at(now_index) = i;
        }
    }

    int print_index = arr_index.back();
    while (print_index != -1) {
        answers.push_back(num.at(print_index) );
        print_index = before.at(print_index);
    }

    sort(answers.begin(), answers.end());

    cout << arr.size() << endl;
    for (int ans : answers) {
        cout << ans << " ";
    }

    return 0;
}

