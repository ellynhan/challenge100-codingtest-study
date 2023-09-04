#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> numbers;
vector<int> answer;

stack<int> st;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;

    numbers.resize(n);
    answer.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    st.push(numbers[n - 1]);
    answer[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--) {
        int value = numbers[i];

        while (!st.empty() && value >= st.top()) {
            st.pop();
        }

        answer[i] = st.empty() ? -1 : st.top();

        st.push(value);
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
}

