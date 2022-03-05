#include <iostream>
#include <queue>
using namespace std;

struct Path
{
    int src;
    int dst;
};

Path *path[401];

bool operator<(Path t, Path u)
{
    return t.src > u.src;
}

priority_queue<Path> pq;
queue<Path> restQ;
int studentNum;
int pathCount;
int moveCount;

void input(void);
void solve(void);
bool checkDuplicated(Path, Path);
void print(int);

int main(int argc, char **argv)
{
    int test_case;
    int T;
    // freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        input();
        solve();
        print(test_case);
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}

void input()
{
    moveCount = 0;
    pathCount = 0;
    cin >> studentNum;
    int src, dst, tmp;

    for (int i = 0; i < studentNum; i++)
    {
        cin >> src >> dst;
        if (src > dst)
        {
            tmp = src;
            src = dst;
            dst = tmp;
        }

        Path newPath;
        newPath.src = src;
        newPath.dst = dst;
        path[pathCount++] = &newPath;
        pq.push(newPath);
    }
}

bool checkDuplicated(Path p, Path q)
{
    int pDst, qSrc;
    pDst = (p.dst - 1) / 2;
    qSrc = (q.src - 1) / 2;

    if (pDst >= qSrc)
        return true;
    return false;
}

void solve()
{
    Path p;
    Path q;
    int qSize;

    while (!pq.empty())
    {
        p = pq.top();
        pq.pop();
        restQ.push(p);
    }

    while (!restQ.empty())
    {
        p = restQ.front();
        restQ.pop();
        // cout << p.src << " " << p.dst << " " << p.moveTime << endl;
        // cout << "size : " << restQ.size() << endl;
        qSize = restQ.size();
        for (int i = 0; i < qSize; i++)
        {
            q = restQ.front();
            restQ.pop();
            // cout << "dup : " << q.src << " " << q.dst << " " << q.moveTime << endl;
            // cout << "i : " << i << endl;
            if (checkDuplicated(p, q))
                restQ.push(q);

            // cout << q.src << endl;
        }
        moveCount++;
    }
}

void print(int testCase)
{
    cout << "#" << testCase << " " << moveCount << endl;
}
