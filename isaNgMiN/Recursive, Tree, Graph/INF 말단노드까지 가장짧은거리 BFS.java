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

    public static int bfs(Node r){
        Queue<Node> bq = new LinkedList<>();
        bq.offer(r);
        int d = 0;

        while(!bq.isEmpty()){
            int size = bq.size();
            for(int i=0; i<size; i++){
                Node tmp = bq.poll();
                if(tmp.lt == null && tmp.rt == null)  {return d;}

                if(tmp.lt != null) bq.offer(tmp.lt);
                if(tmp.rt != null) bq.offer(tmp.rt);
            }
            d++;
        }
        return d;
    }


    public static void main(String args[]){

        Node root = new Node(1);
        root.lt = new Node(2);
        root.lt.lt = new Node(4);
        root.lt.rt = new Node(5);
        root.rt = new Node(3);
        root.rt.lt = new Node(6);
        root.rt.rt = new Node(7);
        root.rt.rt.rt = new Node(8);
        root.rt.rt.lt = new Node(9);

        System.out.print(bfs(root));

    }
}