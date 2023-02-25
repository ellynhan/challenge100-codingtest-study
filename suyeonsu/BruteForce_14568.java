import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int answer = 0;
        for(int a=2; a<n; a+=2) {
            for(int b=1; b<n-a; b++) {
                if(n-a-b >= b+2)
                    answer++;
            }
        }
        System.out.println(answer);
    }
}
