#include <iostream>
#include <vector>
#include <algorithm>
#define boost ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int main(){
    boost;
    int n, x, answer = 0;
    vector<int> a;
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    cin >> x;
    sort(a.begin(), a.end());
    int i=0, j=n-1;
    while(i<j){
        if(a[i]+a[j]==x){
            answer ++;
            i++;
        }else if(a[i]+a[j]>x){
            j--;
        }else{
            i++;
        }
    }
    cout<< answer;
}
