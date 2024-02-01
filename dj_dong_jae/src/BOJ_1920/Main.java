package BOJ_1920;

import java.util.*;

public class Main {

    public static int n, m = 0;
    public static TreeSet<Integer> insert = new TreeSet<>();
    public static ArrayList<Integer> check = new ArrayList<>();

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            insert.add(sc.nextInt());
        }
        m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            check.add(sc.nextInt());
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < m; i++) {
            int checkNow = check.get(i);
            if (insert.contains(checkNow)) {
                result.append("1").append("\n");
            } else {
                result.append("0").append("\n");
            }
        }

        System.out.println(result);

    }

}
