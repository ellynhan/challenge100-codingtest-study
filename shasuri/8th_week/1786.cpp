#include <iostream>
#include <string>
#include <vector>

using namespace std;

string T, P;
int matchCnt = 0;
vector<int> matchLoc;

void input();
void solve();
void print();
vector<int> getPi();

void input()
{
    getline(cin, T);
    getline(cin, P);
}

void solve()
{
    vector<int> pi = getPi();

    int i = 0, j = 0, temp = 0;
    // cout << T.size() - P.size() << endl;

    while (i + j < T.size())
    {
        // cout << T[i + j] << i + j << " : " << P[j] << j << endl;
        if (T[i + j] == P[j])
        {
            if (j == P.size() - 1)
            {
                matchCnt++;
                matchLoc.push_back(i + 1);

                i += j - pi[j] + 1;
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
        else
        {
            if (j > 0)
            {
                i += j - pi[j - 1];
                j = pi[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

vector<int> getPi(void)
{
    int ptnSize = P.size();

    vector<int> piArr(ptnSize, 0);

    int j = 0;

    for (int i = 1; i < ptnSize; i++)
    {
        // cout << j << endl;
        while (j > 0 && P[i] != P[j])
        {
            // cout << j << " <- " << piArr[j - 1] << endl;
            j = piArr[j - 1];
        }

        if (P[i] == P[j])
        {
            j += 1;
            piArr[i] = j;
        }
    }

    return piArr;
}

void print(void)
{
    cout << matchCnt << endl;

    for (int i = 0; i < matchLoc.size(); i++)
    {
        cout << matchLoc[i];
        if (i == matchLoc.size() - 1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}

int main(void)
{
    input();
    solve();
    print();

    return 0;
}