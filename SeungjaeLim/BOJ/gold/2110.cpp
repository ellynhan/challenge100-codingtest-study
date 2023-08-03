#include<stdio.h>
#include<algorithm>

using namespace std;

long long int setup_wifi(int n, int c, long long int left, long long int right);

long long int house[200000];

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%lld", &house[i]);
    }
    sort(house, house + n);
    printf("%lld", setup_wifi(n, c, 1, house[n-1]- house[0]));
}

long long int setup_wifi(int n, int c, long long int left, long long int right)
{
    long long int prev_wifi = house[0];
    long long int mid = (left + right) / 2;
    int cnt_wifi = 1;
    if(left > right)
    {
        return mid;
    }
    for(int i = 1 ; i < n; i++)
    {
        if(house[i] - prev_wifi >= mid)
        {
            cnt_wifi++;
            prev_wifi = house[i];
        }
    }
    if(cnt_wifi >= c)
    {
        return setup_wifi(n, c, mid + 1, right);
    }
    else
    {
        return setup_wifi(n, c, left, mid - 1);
    }
}
