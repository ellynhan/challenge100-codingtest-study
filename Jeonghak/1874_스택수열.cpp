#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, seq[100001], curr=0;
    vector<char> answer;
    vector<int> s;
    cin >> N;
    for(int i=0; i<N; i++) cin >> seq[i];
    for(int i=1; i<=N; i++){
        s.push_back(i);
        answer.push_back('+');
        while(!s.empty() && s.back() == seq[curr]){
            answer.push_back('-');
            curr++;
            s.pop_back();
        }
    }
    if(!s.empty()) cout << "NO\n";
    else
        for(auto i = answer.begin(); i != answer.end(); i++)
            cout << *i << '\n';
    return 0;
}