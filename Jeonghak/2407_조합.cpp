#include<iostream>
#include<string>

using namespace std;
string memo[101][101];

string AddBigNumber(string num1, string num2)
{  
    int sum=0;
    string str_sum;
    while(!num1.empty() || !num2.empty() || sum)
    {
        if(!num1.empty())
        {
            sum += (num1.back() - '0');
            num1.pop_back();
        }
        if(!num2.empty())
        {
            sum += (num2.back() - '0');
            num2.pop_back();
        }
        str_sum += sum%10 + '0';
        sum /= 10;
    }
    reverse(str_sum.begin(), str_sum.end());
    return str_sum;
}

string Combination(int n, int r)
{
    if(n==r || r==0) return "1";
    string &result = memo[n][r];
    if(result != "") return result;
    result = AddBigNumber(Combination(n-1, r-1), Combination(n-1, r));
    return result;
}

int main()
{
    int N, M; 
    string ans;
    cin >> N >> M;
    if(N/2 <= M) M = N-M;
    ans = Combination(N, M);
    cout << ans;
}