// [SEA] 1288 새로운 불면증 치료법 / ??? / 30분
#include<iostream>

using namespace std;

int N, bitMem; // 양 세는 단위와 bit 저장소 선언

void saveBit(int numSave){
    bitMem |= (1 << numSave); // bit 저장소에 현재 숫자를 방문했음을 기록
}

int solve(void){
    int cntNum = 0;
    int numSeen;
    
    while(bitMem != (1 << 10) - 1){ // bit 저장소가 0 ~ 9까지 기록되었는지 
        cntNum++;
        numSeen = cntNum * N;
        while(numSeen != 0){
            saveBit(numSeen % 10); // 숫자의 한 자리 수부터 하나씩 저장
            numSeen /= 10;
        }
    }

    return cntNum;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        bitMem = 0;
        cin >> N;
        cout << "#" << test_case << " " << solve() * N << endl;
	}
	return 0;
}