import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static int N, cnt = 1;
    static int arr[][];
    static boolean visited[][];
    static int move_X[] = {-1, 1, 0, 0};
    static int move_Y[] = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 2][N + 2];
        visited = new boolean[N + 2][N + 2];
        String s;

        for(int i = 1; i <= N; i++) {
            s = br.readLine();

            for(int j = 1; j <= N; j++)
                arr[i][j] = Integer.parseInt(String.valueOf(s.charAt(j - 1)));
        }

        ArrayList<Integer> arrayList = new ArrayList<>();

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(arr[i][j] == 1 && !visited[i][j]) {
                    search(i, j);
                    arrayList.add(cnt);
                    cnt = 1;
                }
            }
        }

        Collections.sort(arrayList);
        System.out.println(arrayList.size());
        for(Integer i : arrayList)
            System.out.println(i);
    }

    public static void search(int i1, int i2) {
        visited[i1][i2] = true;
        int X, Y;

        for(int i = 0; i < 4; i++) {
            X = i1 + move_X[i];
            Y = i2 + move_Y[i];

            if(arr[X][Y] == 1 && !visited[X][Y]) {
                ++cnt;
                search(X, Y);
            }
        }
    }
}