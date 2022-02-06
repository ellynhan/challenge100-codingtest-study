// [SEA] 3316 동아리실 관리하기 / ??? / 2시간
#include<iostream>
#include<string.h>

#define MAX_DAY 10000 // 최대 10000일
#define DIVIDER 1000000007 // 경우의 수 오버플로우를 방지
#define ATTEND_CASE 1 << 4 // ABCD 네 사람의 출석현황 경우의 수

using namespace std;

char managers[MAX_DAY];
int answer;

void manageRoom(void){
    int dp[MAX_DAY][ATTEND_CASE] = { 0 }; // 날마다 인원현황의 경우의 수를 저장하는 dp 생성
    int day = 0;
    int initManagerA = 1; // 첫째날 키를 가진 사람은 무조건 A
    int manager = 1 << (managers[day] - 'A'); // 입력값이 문자이므로, A가 0, B가 1...이 되도록 문자'A'를 빼준다.
    

    for(int i = 1; i < ATTEND_CASE; i++){ // 첫째날만 특별한 경우로 취급
        if((initManagerA&i) && (manager&i)) // A와 첫째날의 관리자가 모두 출석한 경우만
            dp[day][i] = 1; // DP에 1로 저장해준다.
    }

    day++; // 루프는 둘째날부터 시작

    while(managers[day]){
        manager = 1 << (managers[day] - 'A'); // 이날의 관리자
        for(int i = 1; i < ATTEND_CASE; i++){ // i는 오늘의 출석현황을 나타냄
            if(!(manager & i)) continue; // 관리자가 오늘 출석한 경우만 계산한다.

            for(int j = 1; j < ATTEND_CASE; j++){ // j는 어제의 출석현황을 나타냄
                if(!dp[day-1][j]) continue; // 경우의 수가 0인 어제의 출석현황은 계산안함.
                
                if(j & i) // 어제와 오늘의 출석자중 한명이라도 겹치면
                    dp[day][i] = (dp[day][i] + dp[day-1][j]) % DIVIDER; // 경우의 수를 누적시켜 계산(오늘 하루당 어제의 15가지 경우를 전부 고려해준다)
            }
        }
        day++;
    }
    
    answer = 0;
    for(int i = 0; i < ATTEND_CASE; i++){
        answer += dp[day-1][i]; // 마지막날 경우의 수를 전부 더해준다.
        answer %= DIVIDER;
    }
}

void input(void){
    cin >> managers;
}

void solve(void){
    manageRoom();
}

void print(int tc){
    cout << "#" << tc << " " << answer << endl;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(managers,0,sizeof(char)*MAX_DAY); // 입력값을 저장하는 char array 초기화
        input();
		solve();
        print(test_case);
	}
	return 0;
}