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

    public static void bfs(Node root){
        Queue<Node> bq = new LinkedList<>();
        bq.add(root);
        int d = 0;

        while(!bq.isEmpty()){
            Node tmp = bq.poll();
            System.out.print(tmp.data + " ");

            if(tmp.lt != null) bq.add(tmp.lt);
            if(tmp.rt != null) bq.add(tmp.rt);
        }

    }

    public static void main(String args[]){
           Node root = new Node(1);
           root.lt = new Node(2);
           root.rt = new Node(3);
           root.lt.lt = new Node(4);
           root.lt.rt = new Node(5);
           root.rt.lt = new Node(6);
           root.rt.rt = new Node(7);

           bfs(root);
    }
}