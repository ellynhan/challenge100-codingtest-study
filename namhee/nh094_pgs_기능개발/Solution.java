class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int N = progresses.length; // 개발 기능의 개수 (<= 100) = speeds.size
        int front = 0; // pop을 위함. (push는 할 필요 없으므로, rear은 쓰지 않음.)
        
        int count = 0;
        int[] deploy = new int[N];
        while (front < N) { // 모두 꺼낼 때까지
            // 1. 현재 가리키는 것의 작업이 끝났는지 확인한다.
            if (progresses[front] != 100) {
                for (int i = 0; i < N; i++) {
                    progresses[i] += speeds[i];
                    if (progresses[i] > 100) {
                        progresses[i] = 100;
                    }
                }
                continue;
            }
            
            // 2. 작업 끝났다면, 작업이 끝난 모든 기능을 배포한다.
            while (front < N && progresses[front] == 100) {
                deploy[count]++;                
                front++;
            }
            count++;
        }
        
        int[] answer = new int[count];
        for (int i = 0; i < count; i++) {
            answer[i] = deploy[i];
        }
        
        return answer;
    }
}

// 기능은 진도가 100%일 때 서비스에 반영할 수 있다.
// 기능의 개발속도는 모두 다르기 때문에
// 뒤에 잇는 기능이 앞에 있는 기능보다 먼저 개발될 수 있다.
// 그럴 수는 있지만,
// 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다. -> 즉, 앞에 거가 다 되어야 빼낼 수 있다는 뜻. (Queue)

// Answer : 각 배포마다 몇 개의 기능이 배포되는가?
//  -> 배포 횟수를 알아야 하고, 각 배포 때 몇 개의 기능이 배포되는지 알아야 한다.

//  ("Answer"은 소요 날짜 기준이 아닌 각 배포일 기준임을 기억하자.)
