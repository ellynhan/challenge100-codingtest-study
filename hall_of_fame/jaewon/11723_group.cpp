#include <iostream>
using namespace std;

int exist[20] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        string command;
        int x;
        cin >> command;
        if(command == "all"){
            for(int i=0; i<20; i++){
                exist[i] = 1;
            }
        } else if(command == "empty"){
            for(int i=0; i<20; i++){
                exist[i] = 0;
            }
        }else{
            cin >> x;
            if(command == "add"){
                exist[x-1] = 1;
            }else if(command == "remove"){
                exist[x-1] = 0;
            }else if(command == "check"){
                cout<<exist[x-1]<<'\n';
            }else if(command == "toggle"){
                exist[x-1] = 1-exist[x-1];
            }
        }
    }
}

