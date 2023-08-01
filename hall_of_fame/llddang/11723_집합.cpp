#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int bitmask = 0;
    int N; cin >> N;
    
    string str; int num, tmp;
    while(N--){
        cin >> str;
        if(str == "add"){
            cin >> num;
            bitmask |= 1 << num;
        } else if(str == "remove"){
            cin >> num;
            bitmask &= ~(1 << num);
        } else if(str == "check"){
            cin >> num;
            tmp = (bitmask >> num) & 1;
            cout << tmp << "\n";
        } else if(str == "toggle"){
            cin >> num;
            bitmask ^= (1 << num);
        } else if(str == "all"){
            bitmask = (1 << 22) - 1;
        } else if(str == "empty"){
            bitmask = 0;
        }
    }
}
