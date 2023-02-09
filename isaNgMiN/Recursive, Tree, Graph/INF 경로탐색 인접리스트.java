import java.util.*;

class Main{

    static int n,m;
    static ArrayList<ArrayList<Integer>> g;
    static int[] check;
    static int path = 0;

    public static void dfs(int v){
        if(v == n){
            path+=1;
        }
        else{
            for(int x:g.get(v)){
                if(check[x] != 1){
                    check[x] = 1;
                    dfs(x);
                    check[x] = 0;
                }
            }
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        g = new ArrayList<ArrayList<Integer>>();
        for(int i=1; i<=n; i++){
            g.add(new ArrayList<>());
        }
        for(int i=1; i<=m; i++){
            g.get(sc.nextInt()).add(sc.nextInt());
        }

        check = new int[n+1];

        check[1] = 1;
        dfs(1);

        System.out.print(path);
    }
}