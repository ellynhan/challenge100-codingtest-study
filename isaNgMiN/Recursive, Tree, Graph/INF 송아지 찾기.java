// 수직선상의 점프로 목적지까지 가는 뎁스 구하기
// 1 -1 5

// 로직
//  3갈래의 BFS
//  팝하면서 연산후, 위치확인


import java.util.*;


class Main{
    public static int bfs(int s, int e){
        Queue<Integer> bq = new LinkedList<>();
        int[] dis = {-1,1,5};
        int[] check = new int[100001];
        bq.add(s);
        int d = 0;

        while(!bq.isEmpty()){
            int sz = bq.size();
            for(int i=0; i<sz; i++) {
                int now = bq.poll();

                for(int x : dis) {
                    check[now] = 1;
                    if (now + x == e) return d + 1;
                    else if(check[now+x] != 1 && 1 <= now+x && now+x <= 10000) bq.add(now + x);
                }

            }
            d+=1;
        }
        return d;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        int e = sc.nextInt();

        System.out.print(bfs(s,e));
    }
}