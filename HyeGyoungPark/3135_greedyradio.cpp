#include <iostream>
#include <cstdlib>

using namespace std;

int main(void){
    int now,goal,n,gap=0,mini_gap,flag=0,ans;

    cin >> now >> goal;
    mini_gap = abs(now-goal);
    cin >> n;

    int* save = new int[n];

    for(int i=0; i<n; i++){
        cin >> save[i];
    }


    for(int i=0; i<n; i++){
        gap = abs(save[i]-goal);
        if(mini_gap > gap){
            mini_gap = gap;
            flag=1;
        }
    }


    if(flag==0){
        ans = mini_gap;
    }
    else{
        ans = mini_gap+1;
    }

    cout << ans;

    return 0;
}
