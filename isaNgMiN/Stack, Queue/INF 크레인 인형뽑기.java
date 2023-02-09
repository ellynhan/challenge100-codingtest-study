// 각 줄에 맨 위에를 뽑아서 바구니에 넣음 stack
// 바구니에 연속으로 같은 모양(모양은 숫자)이 나오면 두개 사라짐
// 아무것도 없는 줄에서 작동하면 nothing

// board / moves

// moves를 모두 작동시킨후 터진 총 인형수

// 로직.
//  for moves 0 -> m-1
//      for rows 0 -> not 0
//          값을 0으로 바꾸고
//          스택 peek랑 같으면 pop() ans+=2; break;
//                    다르면 push

import java.util.*;

class Main{

    public static int sol(int n, int m, int[][] board, int[] moves){
        int ans = 0;
        Stack<Integer> tans = new Stack<>();

        int tmp;
        for(int i=0; i<m; i++) { //moves
            for(int j=1; j<=n; j++) { // rows
                if(board[j][moves[i]] == 0) continue;
                else{
                    tmp = board[j][moves[i]];
                    board[j][moves[i]] = 0;
                    if(!tans.isEmpty() && tans.peek() == tmp){
                        ans+=2;
                        tans.pop();
                    }else{
                        tans.push(tmp);
                    }
                    break;
                }
            }
        }
        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] board = new int[n+1][n+1];
        for(int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                board[i][j] = sc.nextInt();
            }
        }
        int m = sc.nextInt();
        int[] moves = new int[m];
        for(int i=0; i<m; i++){
            moves[i] = sc.nextInt();
        }

        System.out.print(sol(n,m,board,moves));
    }
}
