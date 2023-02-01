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

    public static void front(Node r){
        if(r == null) return;
        else{
            System.out.print(r.data + " ");
            front(r.lt);
            front(r.rt);
        }
    }

    public static void middle(Node r){
        if(r == null) return;
        else{
            middle(r.lt);
            System.out.print(r.data + " ");
            middle(r.rt);
        }
    }

    public static void end(Node r){
        if(r == null) return;
        else{
            end(r.lt);
            end(r.rt);
            System.out.print(r.data + " ");
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

        front(root);
        System.out.println();
        middle(root);
        System.out.println();
        end(root);


    }

}