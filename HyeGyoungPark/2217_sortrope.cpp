#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    vector<int> rope;

    int num,w,i,j,now,ans=0;

    cin >>num;

    for(i=0; i<num; i++){
        cin >> w;
        rope.push_back(w);
    }

    sort(rope.begin(),rope.end(),greater<>());

    for(i=0;i<num;i++){
        now=rope[i]*(i+1);
        if(now>ans){
            ans = now;
        }
    }

    cout << ans;

    return 0;
}
