
/*
    이분 탐색
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int cal_cnt(int mid, vector<int> &v){
    int sta = v[0];
    int cnt = 1;

    int vsize = v.size();

    for(int i = 1; i < vsize ; i++){
        if(v[i] - sta >= mid){
            cnt++;
            sta = v[i];
        }
    }

    return cnt;
}

int main()
{
    int n, c;

    cin >> n >> c;


    if(n >=2 && n <= 200000 && c>=2 && c<= n){
        vector<int> x(n);

        for(int i = 0; i < n ; i++) cin >> x[i];

        sort(x.begin(), x.end());


        int starti = 1;
        int endi = x[n-1];
        int res = 0;

        while(starti <= endi){
            int mid = (starti + endi )/ 2;

            int cnt = cal_cnt(mid,x);

            if(cnt >= c){
                res = max(res, mid);
                starti = mid + 1;
            }else{
                endi = mid - 1;
            }
        }
        cout << res ;
    }


    return 0;
}
