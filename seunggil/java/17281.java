import java.util.*;
import java.io.*;

class Team{
    ArrayDeque<Integer> base = new ArrayDeque<>(10);
    int score = 0;
    int out = 0;
    int attackIdx = 0;

    void nextInning(){
        for(int i = 0; i < 3; i++){
            base.poll();
            base.add(0);
        }
        out = 0;
    }

    boolean playerOut(int player){
        if(++out == 3){
            nextInning();
            return true;
        }else{
            return false;
        }
        
    }

    // 1이면 안타, 2이면 2루타
    void score(int count, int playerNum){
        for(int i = 0; i < count; i++){
            int player = base.pollFirst();
            if(player != 0){
                score++;
            }
        }
        base.add(playerNum);
        for(int i = 0; i < count-1; i++){
            base.add(0);
        }
    }
    void homeRun(int playerNum){
        while(!base.isEmpty()){
            int player = base.pollFirst();
            if(player != 0){
                score++;
            }
        }
        score++;
        for(int i = 0; i < 3; i++){
            base.add(0);
        }

    }
}

public class Main{
    static ArrayList<Integer> select = new ArrayList<>();

    static int innling;
    static Team t = new Team();

    static int ans = 0;
    static void dfs(boolean[] used, int cnt, int[][] inputData){
        if(cnt == 9){
            
            for(int i = 0; i < innling; i++){
                while(true){
                    int p = select.get(t.attackIdx++);
                    if(t.attackIdx == 9){
                        t.attackIdx = 0;
                    }
                    boolean changeInning = false;
                    switch(inputData[i][p]){
                        case 0:
                            changeInning = t.playerOut(p);
                            break;
                        case 1:
                            t.score(1,p);
                            break;
                        case 2:
                            t.score(2,p);
                            break;
                        case 3:
                            t.score(3,p);
                            break;
                        case 4:
                            t.homeRun(p);
                            break;
                    }
                    if(changeInning){
                        break;
                    }
                }
            }
            ans = Integer.max(ans, t.score);
            t.score = 0;
            t.out = 0;
            t.attackIdx = 0;
        }else{
            if(cnt == 3){
                select.add(1);
                used[1] = true;
                dfs(used, cnt+1, inputData);
                used[1] = false;
                select.remove(select.size()-1);
            }else{
                for(int i = 2; i < 10; i++){
                    if(!used[i]){
                        select.add(i);
                        used[i] = true;
                        dfs(used, cnt+1, inputData);
                        used[i] = false;
                        select.remove(select.size()-1);
                    }
                }
            }
            
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        innling = Integer.parseInt(re.readLine());

        int[][] inputData = new int[innling][10];

        for(int i = 0; i < innling; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            for(int j = 1; j < 10; j++){
                inputData[i][j] = Integer.parseInt(token.nextToken());
            }
        }

        boolean[] used = new boolean[10];
        for(int i = 0; i < 3; i++){
            t.base.add(0);
        }
        dfs(used,0,inputData);
        
        System.out.print(ans);
        re.close();
    }
}