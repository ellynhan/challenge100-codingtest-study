// [BOJ] 1로 만들기2 / 실버1 / 1시간
// https://www.acmicpc.net/problem/12852

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 999999 // 초기 수치

struct calcRecord
{
    int path;             // 최솟값의 출처 분기를 저장
    int pathLength = MAX; // 계산 최솟값
};

bool operator<(calcRecord t, calcRecord u)
{
    return t.pathLength < u.pathLength;
}

vector<calcRecord> DP(1000000); // DP[n] = (n+1에서  1까지의 최소 연산 횟수라고 생각한다.)
int N;                          // 입력 값 N
calcRecord NRecord;             // N의 최소 연산 횟수 및 최솟값 출처 기록

void input(void)
{
    cin >> N;
}

calcRecord branch(int n)
{
    calcRecord minPath;
    calcRecord twoDivPath;
    calcRecord threeDivPath;
    calcRecord oneSubPath;

    if (DP[n - 1].pathLength != MAX) // 기록된 수라면
        return DP[n - 1];            // 기록된 값을 그대로 리턴

    if (n % 2 == 0)                 // 2로 나눌 수 있으면
        twoDivPath = branch(n / 2); // 2로 나눈 다음 분기

    if (n % 3 == 0)                   // 3으로 나눌 수 있으면
        threeDivPath = branch(n / 3); // 3으로 나눈 다음 분기

    oneSubPath = branch(n - 1); // 1을 빼고 분기

    if (twoDivPath.pathLength < threeDivPath.pathLength)
    {
        minPath.pathLength = twoDivPath.pathLength;
        minPath.path = n / 2; // 어떤 분기에서 최솟값이 왔는지 기록
    }
    else if (threeDivPath.pathLength != MAX)
    {
        minPath.pathLength = threeDivPath.pathLength;
        minPath.path = n / 3; // 어떤 분기에서 최솟값이 왔는지 기록
    }

    if (oneSubPath.pathLength < minPath.pathLength)
    {
        minPath.pathLength = oneSubPath.pathLength;
        minPath.path = n - 1; // 어떤 분기에서 최솟값이 왔는지 기록
    }

    minPath.pathLength++; // 3개의 분기의 값을 모두 비교한 뒤, 최솟값에 계산했다는 의미로 1을 더함

    DP[n - 1] = minPath; // DP에 기록
    return minPath;
}

void solve(void)
{
    DP[0].path = 0; // 1은 연산 횟수가 0이므로
    DP[0].pathLength = 0;
    NRecord = branch(N); // 연산횟수에 N의 분기 값을 입력
}

void print(void)
{
    cout << NRecord.pathLength << endl;

    cout << N << " ";
    int i = N;
    while (i >= 2)
    {
        cout << DP[i - 1].path << " ";
        i = DP[i - 1].path; // Value를 다시 index로 하여 경로를 추적
    }
}

int main()
{
    input();
    solve();
    print();

    return 0;
}
