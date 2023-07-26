import java.util.*;

class Solution {
    static int score = 0;
    static int[] answerScore;
    static int[] scoreTable;
    
    // index, 쓴 화살, 총 화살 갯수, 어피치가 쏜 화살 정보
    static void dfs(int idx, int now, int n, int[] info){
        // 다 쓴 화살
        if(now == n || idx == 10){
            scoreTable[10] = n - now;
            int nowScore = 0;
            for(int i = 0; i < 11; i++){
                if(scoreTable[i] > info[i]){
                    nowScore += 10-i;
                }else if(info[i] != 0){
                    nowScore -= 10-i;
                }
            }
            
            if(nowScore > score){
                answerScore = Arrays.copyOf(scoreTable, scoreTable.length);
                score = nowScore;
            }else if(nowScore == score){
                for(int i = 9; i >= 0; i--){
                    if(scoreTable[i] > answerScore[i]){
                        answerScore = Arrays.copyOf(scoreTable, scoreTable.length);
                    }else if(scoreTable[i] < answerScore[i]){
                        break;
                    }
                }
            }
            scoreTable[10] = 0;
        }else{
            // 해당 점수 획득
            if(info[idx]+1 + now <= n){
                scoreTable[idx] = info[idx]+1;
                dfs(idx+1, now + scoreTable[idx], n, info);
            }
            
            
            // 획득 x
            scoreTable[idx] = 0;
            dfs(idx+1, now, n, info);
        }
    
    }
    public int[] solution(int n, int[] info) {
        answerScore = new int[11];
        scoreTable = new int[11];
        
        dfs(0,0,n,info);    
        
        if(score == 0){
            return new int[]{-1};
        }else{
            return answerScore;
        }
    }
}