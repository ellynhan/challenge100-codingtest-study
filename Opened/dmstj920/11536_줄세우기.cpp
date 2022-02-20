#include <iostream>

using namespace std;

int main()
{
    int num, dec = 0, inc = 0;
    string name[21];
    string cmp;

    cin >> num;

    for(int i=0; i<num; i++){
        cin >> name[i];
    }

    cmp = name[0];
    for(int i=1; i<num; i++){
        if(cmp < name[i]){
            if(dec != 0) break;
            inc += 1;
        }
        else{
            if(inc != 0) break;
            dec += 1;
        }

        cmp = name[i];
    }

    if(dec == num-1) cout << "DECREASING";
    else if(inc == num-1 ) cout << "INCREASING";
    else cout << "NEITHER";

    return 0;
}
