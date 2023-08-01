#include <iostream>
#include <vector>
using namespace std;

struct cloth{
    cloth(string t, int c):
        type{t}, cnt{c}{};
    string type;
    int cnt;
};

int main(){
    int T; cin >> T;
    int i;
    while(T--){
        int num; cin >> num;
        vector<cloth> vec;
        while(num--){
            string name, type;
            cin >> name >> type;
            for(i=0; i<vec.size(); i++){
                if(vec[i].type == type){
                    vec[i].cnt++;
                    break;
                }
            }
            if(i == vec.size()){
                vec.push_back(cloth(type, 1));
            }
        }

        int cnt=1;
        for(i=0; i<vec.size(); i++){
            cnt *= (vec[i].cnt + 1);
        }
        cout << cnt - 1 << "\n";
        vec.clear();
    }
}
