


import java.util.*;

class Coor implements Comparable<Coor>{
    public int x, y;
    Coor(int x, int y){
        this.x = x;
        this.y = y;
    }
    @Override
    public int compareTo(Coor e){
        if(this.x == e.x) return this.y - e.y;
        else return this.x - e.x;
    }
}

class Main{

    public static ArrayList<Coor> sol(int n, ArrayList<Coor> coora){

        Collections.sort(coora);

        return coora;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Coor> coora = new ArrayList<>();
        for(int i=0; i<n; i++){
            coora.add(new Coor(sc.nextInt(), sc.nextInt()));
        }

        ArrayList<Coor> ans = sol(n,coora);
        for(Coor e:ans) System.out.println(e.x + " " + e.y);
    }
}