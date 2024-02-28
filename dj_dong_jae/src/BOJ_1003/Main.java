package BOJ_1003;

import java.util.*;

class Node {
    int countZero;
    int countOne;
    Node(int countZero, int countOne) {
        this.countZero = countZero;
        this.countOne = countOne;
    }
}

public class Main {

    public static ArrayList<Node> d = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        d.add(new Node(1, 0)); // f(0)
        d.add(new Node(0, 1)); // f(1)
        for (int i = 2; i < 41; i++) {
            Node preNode = d.get(i - 1);
            Node prepreNode = d.get(i - 2);
            d.add(new Node(preNode.countZero + prepreNode.countZero, preNode.countOne + prepreNode.countOne));
        }

        int t = sc.nextInt();
        int[] list = new int[t];
        for (int i = 0; i < t; i++) {
            list[i] = sc.nextInt();
        }

        for (int i : list) {
            System.out.println(d.get(i).countZero + " " + d.get(i).countOne);
        }
    }

}
