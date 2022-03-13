#include<iostream>
#include<map>
using namespace std;

int main()
{
    int T, N;
    cin >> T;
    while(T--){
        int idx, res=1;
        map<string, int> m;
        cin >> N;
        for(int i=0; i<N; i++){
            string a, b;
            cin >> a >> b;
            if(m.find(b) == m.end())
                m.insert({b, 1});
            else{
                m[b]++;
            }
        }
        for(auto i = m.begin(); i!=m.end(); i++){
            res *= i->second + 1;   // 입지 않는 경우도 추가해서 곱해 줌
        }
        res -= 1;   // 알몸인 경우는 제외
        cout << res << '\n';
    }
}