#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string eq;
    vector<int> n;
    vector<char> op;
    string num;
    int sum = 0;
    int tmp = 0;
    bool minus = false;

    cin >> eq;
    for(int i=0; i<eq.size(); i++)
    {
        if ('0' <= eq[i] && eq[i] <= '9')
            num += eq[i];
        else if(eq[i] == '+')
        {
            if (minus)
                tmp += stoi(num);
            else
                sum += stoi(num);
            num = "";
        }
        else
        {
            tmp += stoi(num);
            if(minus){
                sum -= tmp;
            }
            else{
                minus = true;
                sum += tmp;
            }
            tmp = 0;
            num = "";
        }
    }
    tmp += stoi(num);
    if (minus)
    {
        sum -= tmp;
    }
    else
    {
        sum += tmp;
    }
    cout << sum << '\n';
    return 0;
}
