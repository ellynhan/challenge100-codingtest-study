import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Solution {

    public int solution(int[] arrayA, int[] arrayB) {
        int gdcA = arrayA[0];
        for (int i = 1; i < arrayA.length; i++) {
            gdcA = gdc(gdcA, arrayA[i]);
        }
        int gdcB = arrayB[0];
        for (int i = 1; i < arrayB.length; i++) {
            gdcB = gdc(gdcB, arrayB[i]);
        }
        List<Integer> candidatesA = getList(gdcA);
        List<Integer> candidatesB = getList(gdcB);

        int answer = 0;
        for (Integer candidate : candidatesA) {
            boolean flag = true;
            for (int i = 0; i < arrayB.length; i++) {
                if (arrayB[i] % candidate == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                answer = Math.max(answer, candidate);
            }
        }
        for (Integer candidate : candidatesB) {
            boolean flag = true;
            for (int i = 0; i < arrayA.length; i++) {
                if (arrayA[i] % candidate == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                answer = Math.max(answer, candidate);
            }
        }

        return answer;
    }

    static int gdc(int a, int b) { //최대 공약수
        if (a < b) // 유클리드 호제법 조건
        {
            int temp = a;
            a = b;
            b = temp;
        }
        while (b != 0) { // 유클리드 호제법
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    static List<Integer> getList(int n) {
        int sqrt = (int) Math.sqrt(n); // 100의 제곱근은 10
        List<Integer> arr = new ArrayList<>(); // 약수 받을 ArrayList

        for (int i = 1; i <= sqrt; i++) {
            if (n % i == 0) { // 약수 중 작은 수 저장
                arr.add(i);
                if (n / i != i) { // 약수 중 큰 수 저장
                    arr.add(n / i);
                }
            }
        }
        // Java 8 이후 사용 가능
        arr.sort(Comparator.naturalOrder());

        return arr;
    }
}