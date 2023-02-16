import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
 
public class Solution {
     
    static int N;
    static int[][] S;
    static int [] a, b;
    static List<int[]> caseA, caseB;
    static int minGap;
    static StringBuilder answer = new StringBuilder();
 
    public static void main(String[] args) throws NumberFormatException, IOException {
         
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t=1; t<=T; t++) {
            N = Integer.parseInt(br.readLine());
            S = new int[N][N];
            for(int i=0; i<N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=0; j<N; j++) {
                    S[i][j] = Integer.parseInt(st.nextToken());
                }
            }
             
            a = new int[N/2];
            b = new int[N/2];
            caseA = new ArrayList<int[]>();
            caseB = new ArrayList<int[]>();           
            combinations(0, 0);
             
            minGap = Integer.MAX_VALUE;
            for(int c=0; c<caseA.size(); c++) {
                int sumA = 0;
                for(int i : caseA.get(c)) {
                    for(int j : caseA.get(c)) {
                        sumA += S[i][j];
                        sumA += S[j][i];
                    }
                }
                int sumB = 0;
                for(int i : caseB.get(c)) {
                    for(int j : caseB.get(c)) {
                        sumB += S[i][j];
                        sumB += S[j][i];
                    }
                }
                minGap = Math.min(minGap, Math.abs(sumA-sumB)/2); 
            }
            answer.append('#').append(t).append(' ').append(minGap).append('\n');
        }
        System.out.println(answer);
    }
     
    private static void combinations(int cnt, int idx) {
        if(cnt == N/2) {
            HashSet<Integer> set = new HashSet<Integer>();
            for(int i=0; i<N/2; i++) 
                set.add(a[i]);
            int pos = 0;
            for(int i=0; i<N; i++) {
                if(!set.contains(i))
                    b[pos++] = i;
            }
            caseA.add(Arrays.copyOf(a, N/2));
            caseB.add(Arrays.copyOf(b, N/2));
            return;
        }
        for(int i=idx; i<N; i++) {
            a[cnt] = i;
            combinations(cnt+1, i+1);
        }
    }
     
}
