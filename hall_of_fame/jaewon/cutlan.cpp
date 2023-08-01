#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

#define ll long long
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int n,k;
    cin >> n >> k; //k is target
    vector<ll> v;

    for(int i=0; i<n; i++){
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }  
    sort(v.begin(), v.end());
    ll mini=1,maxi=v[n-1];
    ll mid = (mini+maxi)/2;
    ll answer = 0;
    while(mini<=maxi){
        int total = 0;
        for(int i=0; i<n; i++){
            total += v[i]/mid;
        }
        if(total>=k){
            if(answer<mid){
                answer = mid;
            }
            mini = mid + 1;
        }else{
            maxi = mid -1;
        }
        mid = (mini+maxi)/2;
    }
    cout<<answer;
}

