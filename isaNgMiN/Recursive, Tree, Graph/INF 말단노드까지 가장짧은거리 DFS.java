//말단노드까지의 가장짧은 경로


//로직
// 노드정의
// dfs. d정의 -> min
import java.util.*;


class Node{
    int data;
    Node lt, rt;

    public Node(int data){
        this.data = data;
        lt = rt = null;
    }
}

class Main{

    public static int dfs(int d, Node r){
        if(r.rt == null || r.lt == null){
            return d;
        }else{
            return Math.min(dfs(d+1,r.lt), dfs(d+1,r.rt));
        }
    }


    public static void main(String args[]){

        Node root = new Node(1);
        root.lt = new Node(2);
        root.lt.lt = new Node(4);
        root.lt.rt = new Node(5);
        root.rt = new Node(3);
//        root.rt.lt = new Node(3);
//        root.rt.rt = new Node(3);
//        root.rt.rt.rt = new Node(3);
//        root.rt.rt.lt = new Node(3);

        System.out.print(dfs(0, root));

    }
}