#include <iostream>
#include <string>
using namespace std;
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N, cnt;
    string ps;
    cin >> N;
    while(N--){
        cnt=0;
        cin >> ps;
        for(int i=0; i<ps.size(); i++)
        {
            if(ps[i]=='(')cnt++;
            else {
                cnt--;
                if(cnt<0) {
                    cout << "NO\n";
                    break;
                }
            }
        }
        if(cnt==0) cout << "YES\n";
        if(cnt>0) cout << "NO\n";
    }
}
