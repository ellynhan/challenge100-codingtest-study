// [BOJ] 1로 만들기 / 실버3 / 30분
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>

using namespace std;

#define MAX 999999 // 초기 수치

vector<int> DP(1000000, -1); // DP[n] = (n+1에서  1까지의 최소 연산 횟수라고 생각한다.)
int N;                       // 입력 값 N
int calcCount;               // N의 최소 연산 횟수

void input(void)
{
    cin >> N;
}

int branch(int n)
{
    int minDepth;
    int twoDivDepth = MAX;   // 최댓값으로 초기화
    int threeDivDepth = MAX; // 최댓값으로 초기화
    int oneSubDepth = MAX;   // 최댓값으로 초기화

    if (DP[n - 1] != -1) // 기록된 수라면
    {
        return DP[n - 1]; // 기록된 값을 그대로 리턴
    }

    if (n % 2 == 0) // 2로 나눌 수 있으면
    {
        twoDivDepth = branch(n / 2); // 2로 나눈 다음 분기
    }

    if (n % 3 == 0) // 3으로 나눌 수 있으면
    {
        threeDivDepth = branch(n / 3); // 3으로 나눈 다음 분기
    }

    oneSubDepth = branch(n - 1); // 1을 빼고 분기

    minDepth = min(min(twoDivDepth, threeDivDepth), oneSubDepth) + 1; // 3개의 분기의 값을 모두 비교한 뒤, 최솟값에 계산했다는 의미로 1을 더함

    DP[n - 1] = minDepth; // DP에 기록
    // cout << n << " : " << DP[n - 1] << endl;
    return minDepth;
}

void solve(void)
{
    for (int i = 0; i < 1000000; i++)
        DP[i] = -1; // DP를 -1로 초기화, -1이 아니라면 기록된 수로 판단.

    DP[0] = 0; // 1은 연산 횟수가 0이므로

    calcCount = branch(N); // 연산횟수에 N의 분기 값을 입력
}

void print(void)
{
    cout << calcCount;
}

int main()
{
    input();
    solve();
    print();

    return 0;
}
