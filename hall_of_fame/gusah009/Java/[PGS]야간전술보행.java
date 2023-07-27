import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class Solution {

    public int solution(int distance, int[][] scope, int[][] times) {
        List<Guard> guards = new ArrayList<>();
        for (int i = 0; i < scope.length; i++) {
            Arrays.sort(scope[i]);
            guards.add(new Guard(scope[i][0], scope[i][1], times[i][0], times[i][1]));
        }
        guards.add(new Guard(distance + 1, distance + 2, 0, 0));
        guards.sort(Comparator.comparingInt(g -> g.startInclusive));

        int answer = 0;
        int guardIndex = 0;
        while (true) {
            Guard currentGuard = guards.get(guardIndex);
            while (answer < distance && answer < currentGuard.startInclusive) {
                answer++;
            }
            if (answer == distance) {
                break;
            }
            boolean catchFlag = false;
            while (currentGuard.startInclusive <= answer &&
                    answer <= currentGuard.endInclusive) {
                if ((answer - 1) % (currentGuard.workingTime + currentGuard.breakTime) < currentGuard.workingTime) {
                    catchFlag = true;
                    break;
                }
                answer++;
            }
            if (catchFlag) {
                break;
            }
            guardIndex++;
        }
        return answer;
    }

    static class Guard {

        int startInclusive;
        int endInclusive;
        int workingTime;
        int breakTime;

        public Guard(int startInclusive, int endInclusive, int workingTime, int breakTime) {
            this.startInclusive = startInclusive;
            this.endInclusive = endInclusive;
            this.workingTime = workingTime;
            this.breakTime = breakTime;
        }
    }
}