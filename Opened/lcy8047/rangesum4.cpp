#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums;
    vector<int> sums;
    int sum = 0;
    int n, m;
    int num;
    int l=0, r=0;
    int i, j;

    cin >> n >> m;
    for(int k=0; k<n; k++)
    {
        cin >> num;
        nums.push_back(num);

        sum += num;
        sums.push_back(sum);
    }
    
    for(int k=0; k<m; k++)
    {
        cin >> i >> j;
        i --;
        j --;
        if( i == 0 )
            cout << sums[j] << '\n';
        else
            cout << sums[j] - sums[i-1] << '\n';
    }
    return 0;
}