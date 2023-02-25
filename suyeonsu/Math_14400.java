import java.util.*;
import static java.lang.Math.abs;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for(int i=0; i<n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        Arrays.sort(x);
        int mid_x = x[n/2];
        Arrays.sort(y);
        int mid_y = y[n/2];

        long answer = 0;
        for(int i=0; i<n; i++) {
            answer += abs(x[i]-mid_x) + abs(y[i]-mid_y);
        }
        System.out.println(answer);
    }
}
