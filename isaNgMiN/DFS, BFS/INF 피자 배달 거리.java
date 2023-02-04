// 0 빈칸 / 1 집 / 2 피자집
// 지도 NxN index:1~N
// 피자배달거리: 모든 피자집 각각의 거리중 최소값 (x편차 + y편차)
// 피자집 M개만 남기고 모두 없애기 -> 피자배달거리가 최소가 되는 M개 선택 -> 이때의 sum(피자배달거리)

// dfs
//  2에 대한 거리를 만들어놓고
//  m==d 거리계산 min값저장


import java.util.*;


class Coor{
    int x;
    int y;
    public Coor(int x, int y){
        this.x =x;
        this.y =y;
    }
}


class Main{

    static int n,m;
    static int[][] b;

    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,-1,0,1};

    static ArrayList<Coor> piz = new ArrayList<>();
    static ArrayList<Coor> hou = new ArrayList<>();
    static Coor[] checked_piz;
    static int min = Integer.MAX_VALUE;
    static int num = 0;

    public static void dfs(int d, int st){
        if(d==m) {
            num+=1;
//            System.out.println("hi");
//            for(Coor p:checked_piz) System.out.println(p.x + ", " + p.y);
//            System.out.println("bye");

            int sum=0;
            for (int i = 0; i < hou.size(); i++) {
                int dis = Integer.MAX_VALUE;
                for (Coor p : checked_piz) {
                    int tmp = Math.abs(p.x - hou.get(i).x) + Math.abs(p.y - hou.get(i).y);
                    dis = Math.min(tmp, dis);
                }
                sum+=dis;
            }
            min = Math.min(min, sum);
        } else{
            for(int i=st; i<piz.size(); i++) {
                checked_piz[d] = piz.get(i);
                dfs(d + 1, i+1);
            }
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        b = new int[n+2][n+2];
        for(int i=1; i<=n; i++){
            for(int j=1;j<=n;j++){
                b[i][j] = sc.nextInt();
                if(b[i][j] == 2){
                    piz.add(new Coor(i,j));
                }
                if(b[i][j] == 1){
                    hou.add(new Coor(i,j));
                }
            }
        }
        checked_piz = new Coor[m];

        dfs(0,0);
        System.out.println(min);

//        System.out.println(num);

//        for(int i=1; i<=n; i++){
//            for(int j=1;j<=n;j++) {
//                System.out.printf("%-2d", dist[i][j]);
//            }
//            System.out.println();
//        }

    }
}