#include <iostream>

using namespace std;

int main()
{
    int num, i, j, chk = 0, flag = 0;
    cin >> num;
    string vps[100];

    for(i=0; i<num; i++)
        cin >> vps[i];
    
    for(i=0; i<num; i++){
        for(j=0; j<vps[i].size(); j++){
            if(vps[i][j] == ')' && chk == 0){
                flag = 1;
                break;
            }

            if(vps[i][j] == '(') chk += 1;
            else chk -= 1;
        }

        if(chk == 0 && flag == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";

        chk = 0;
        flag = 0;
    }


    return 0;
}

