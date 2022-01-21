#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int present, want, num, i, star, cnt=0, chk = 0;

    cin >> present >> want;
    cin >> num;

    int minMHz = abs(present - want);

    for(i=0; i<num; i++){
        cin >> star;
        if(minMHz > abs(star - want)){
            minMHz = abs(star - want);
            chk = 1;
        }
    }

    if(chk == 1){
        cnt += minMHz + 1;
    }

    else{
        cnt += minMHz;
    }

    cout << cnt;

    return 0;
}
