#include <bits/stdc++.h>

using namespace std;

class Meeting
{
public:
    Meeting(int s, int e)
        : start(s)
        , end(e)
        {}

    int start;
    int end;
};

bool compare(Meeting m1, Meeting m2)
{
    if(m1.end == m2.end)
        return m1.start < m2.start;
    return m1.end < m2.end;
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int s, e;
    int endTime = 0;
    int count = 1;
    vector<Meeting> m;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s >> e;
        m.push_back(Meeting(s, e));
    }

    sort(m.begin(), m.end(), compare);

    endTime = m[0].end;
    for(int i=1; i<m.size(); i++)
    {
        if(m[i].start >= endTime)
        {
            count ++;
            endTime = m[i].end;
        }
    }

    cout << count << '\n';
    return 0;
}