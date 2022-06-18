#include <string>
#include <vector>
#include <list>
using namespace std;

class profile{
public:
    int id;
    int win = 0;
    int lose = 0;
    int heavyWin = 0; // 자기보다 무거운 복서를 이긴 횟수
    int weight;
    profile(int id, int weight) : id(id), weight(weight){}
    
    bool operator< (const profile& other) const {
        double winrate = (win+lose) == 0 ? 0 : win /static_cast<float>(win + lose);
        double otherWinrate = (other.win+ other.lose) == 0 ? 0 : other.win /static_cast<float>(other.win + other.lose);
        if(winrate != otherWinrate)
            return winrate > otherWinrate;
        if(heavyWin != other.heavyWin)
            return heavyWin > other.heavyWin;
        if(weight != other.weight)
            return weight > other.weight;
        return id < other.id;
    }
};
vector<int> solution(vector<int> weights, vector<string> head2head) {
    list<profile> ranking;
    
    for(int i = 0; i < weights.size(); i++)
        ranking.emplace_back(i, weights[i]);
    
    for(profile& player : ranking)
        for(int j = 0; j < head2head[player.id].size(); j++)
            switch(head2head[player.id][j]){
                    case 'W':
                        player.win++;
                        if(player.weight < weights[j])
                            player.heavyWin++;
                        break;
                    case 'L':
                        player.lose++;
                        break;
            }
    
    ranking.sort(less<profile>());
    vector<int> answer;
    answer.reserve(weights.size());
    for(const profile& iter : ranking)
        answer.push_back(iter.id+1);
    
    return answer;
}