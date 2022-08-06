import java.util.Arrays;

class Solution {

    public int[] solution(int N, int[] stages) {
        double arr[][] = new double[N][2];
        int M[] = new int[N];

        for(int i = 0; i < stages.length; i++) {
            if(stages[i] != N + 1) {
                arr[stages[i] - 1][0]++;

                for(int j = 0; j <= stages[i] - 1; j++)
                    M[j]++;
            }
            else
                for(int j = 0; j < N; j++) M[j]++;
        }

        for(int i = 0; i < N; i++) {
            if(M[i] == 0 && arr[i][0] == 0) arr[i][0] = 0;
            else arr[i][0] /= M[i];
            arr[i][1] = i + 1;
        }

        Arrays.sort(arr, (o1, o2) -> {
            if(o1[0] != o2[0])
                return Double.compare(o2[0], o1[0]);

            return Double.compare(o2[0], o1[0]);
        });

        int answer[] = new int[N];

        for(int i = 0; i < N; i++)
            answer[i] = (int)arr[i][1];

        return answer;
    }
}
