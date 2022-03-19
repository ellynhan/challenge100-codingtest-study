import java.util.*;
import java.io.*;

class Main{
    static int[][] map = new int[9][9];
    static int[] row = new int[9];
    static int[] col = new int[9];
    static int[] square = new int[9];
    static boolean finish = false;

    // index, 몇개 채웠는지 확인
    static void dfs(int index, int now){
        if(now == 81){
            StringBuilder ans = new StringBuilder();
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    ans.append(map[i][j]);
                }ans.append('\n');
            }
            System.out.print(ans);
            finish = true;
            return;
        }
        int r = index / 9;
        int c = index % 9;
        while(map[r][c] != 0){
            index++;
            r = index / 9;
            c = index % 9;
        }

        for(int j = 1; j < 10; j++){
            if((row[r] & (1 << j)) == 0
                && (col[c] & (1 << j)) == 0
                && (square[(r / 3) * 3 + c/3] & (1 << j)) == 0){
                    row[r] |= (1 << j);
                    col[c] |= (1 << j);
                    square[(r / 3) * 3 + c/3] |= (1 << j);
                    map[r][c] = j;
                    dfs(index+1, now+1);
                    
                    if(finish){
                        return;
                    }else{
                        map[r][c] = 0;
                        row[r] &= ~(1 << j);
                        col[c] &= ~(1 << j);
                        square[(r / 3) * 3 + c/3] &= ~(1 << j);
                    }
            }
        }
            
    }

    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        int cnt = 0;
        for(int i = 0; i < 9; i++){
            String str = re.readLine();
            for(int j = 0; j < 9; j++){
                int n = str.charAt(j) -'0';
                map[i][j] = n;
                if(n != 0){
                    row[i] |= (1 << n);
                    col[j] |= (1 << n);

                    square[(i / 3) * 3 + j/3] |= (1 << n);

                    cnt++;
                }
                
            }
        }
        dfs(0,cnt);

        
        re.close();
    }
}