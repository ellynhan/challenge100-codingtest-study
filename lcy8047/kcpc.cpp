#include <bits/stdc++.h>

using namespace std;

struct TeamScore {
    int id;
    int *problems;
    int totalScore;
    int lastSubmit;
    int submitCount;
};

bool compare( TeamScore t1, TeamScore t2 )
{
    if( t1.totalScore == t2.totalScore ) {
        if( t1.submitCount == t2.submitCount ) {
            return t1.lastSubmit < t2.lastSubmit;
        }
        return t1.submitCount < t2.submitCount;
    }
    return t1.totalScore > t2.totalScore;
}

int main( void )
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int n, k, t, m;
    int i, j, s;

    vector<TeamScore> scores;
    int *teams;

    cin >> T;
    for( int testcase=0; testcase<T; testcase++ ) {
        cin >> n >> k >> t >> m;
        scores.clear();
        teams = new int[n];
        for( int p=0; p<n; p++ ) {
            TeamScore ts;
            ts.id = p+1;
            ts.problems = new int[k];
            memset(ts.problems, 0, sizeof(int)*k);
            ts.totalScore = 0;
            ts.lastSubmit = 0;
            ts.submitCount = 0;
            scores.push_back(ts);
        }

        for( int p=0; p<m; p++ ) {
            cin >> i >> j >> s;
            i = i-1;
            j = j-1;
            if( scores[i].problems[j] < s ) {
                scores[i].totalScore -= scores[i].problems[j];
                scores[i].problems[j] = s;
                scores[i].totalScore += s;
            }
            scores[i].lastSubmit = p;
            scores[i].submitCount ++;
        }
        
        sort(scores.begin(), scores.end(), compare);

        for( int p=0; p<n; p++ ) {
            if( scores[p].id == t ) {
                cout << p+1 << '\n';
                break;
            }
        }
    }

    return 0;
}