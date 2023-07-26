#include <string> // 20m
#include <vector>
#include <map>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MBTI_TYPE 4

map<char, int> m;

char mbti[MBTI_TYPE][2] = {{'R', 'T'}, {'F', 'C'}, {'M', 'J'}, {'A', 'N'}};

void init()
{
    FOR(i, MBTI_TYPE) {
        FOR(j, 2) {
            m[mbti[i][j]] = 0;
        }
    }
}

void setMbti(char a, char b, int score)
{
    if (score > 0) {
        m[b] += score;
    } else if (score < 0) {
        m[a] += -score;
    }
}

char getMbti(int typeNum)
{
    int mbtiScore1 = m[mbti[typeNum][0]];
    int mbtiScore2 = m[mbti[typeNum][1]];
    if (mbtiScore1 < mbtiScore2) {
        return mbti[typeNum][1];
    } else if (mbtiScore1 > mbtiScore2) {
        return mbti[typeNum][0];
    } else if (mbtiScore1 == mbtiScore2) {
        return mbti[typeNum][0] < mbti[typeNum][1] ? mbti[typeNum][0] : mbti[typeNum][1];
    }
}

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";

    init();

    FOR(i, survey.size())
    {
        setMbti(survey[i][0], survey[i][1], choices[i] - 4);
    }

    FOR(i, MBTI_TYPE)
    {
        answer += getMbti(i);
    }

    return answer;
}