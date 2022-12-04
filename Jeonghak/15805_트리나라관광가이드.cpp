#include<iostream>
#include<set>

using namespace std;
int main()
{
    int *ans, *tree, N;
;
    set<int> s; 
    cin >> N;
    ans = new int[N];
    tree = new int[N];
    for(int i=0;i<N; i++) cin >>  tree[i];
    ans[tree[0]] = -1;
    s.insert( tree[0]);
    for(int i=1; i<N; i++){
        if(s.count( tree[i])) continue;
        ans[ tree[i]] =  tree[i-1];
        s.insert( tree[i]);
    }
    cout << s.size() << '\n';
    for(int i=0; i<s.size(); i++) cout << ans[i] << ' ';
    delete [] ans;
    delete [] tree;
}