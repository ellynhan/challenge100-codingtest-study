package BOJ_10810;
import java.util.*;
import java.io.*;

//public class Main {
//    public static long[] array = new long[101];
//    public static long n, m;
//
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(br.readLine());
//
//        n = Long.parseLong(st.nextToken());
//        m = Long.parseLong(st.nextToken());
//
//        for (long i = 0; i < m; i++) {
//            st = new StringTokenizer(br.readLine());
//            long start = Long.parseLong(st.nextToken());
//            long end = Long.parseLong(st.nextToken());
//            long num = Long.parseLong(st.nextToken());
//            for (long j = start; j <= end; j++) {
//                array[(int)j] = num;
//            }
//        }
//
//        StringBuilder sb = new StringBuilder();
//        for (long i = 1; i <= n; i++) {
//            sb.append(array[(int)i]).append(" ");
//        }
//        System.out.println(sb);
//    }
//}

//import java.util.Scanner;
//
//public class Main {
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//
//        int baskets = scanner.nextInt();
//        int caseNum = scanner.nextInt();
//        int[] basketArr = new int[baskets];
//
//        for (int i = 0; i < caseNum; i++) {
//            int range1 = scanner.nextInt();
//            int range2 = scanner.nextInt();
//            int ballNum = scanner.nextInt();
//
//            for (int j = range1-1; j <= range2-1; j++) {
//                basketArr[j] = ballNum;
//            }
//        }
//        for (int i = 0; i < basketArr.length; i++) {
//            System.out.print(basketArr[i]+" ");
//        }
//    }
//}

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int caseNum = scanner.nextInt();
        String[] strArray = new String[caseNum+1];

        for (int i = 0; i < strArray.length; i++) {
            strArray[i] = scanner.nextLine();
        }
        for (int i = 1; i < strArray.length; i++) {
            System.out.print(strArray[i].charAt(0));
            System.out.println(strArray[i].charAt((strArray[i].length()-1)));
        }
    }
}
