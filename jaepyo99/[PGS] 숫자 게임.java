// 이기면 승점1
// 최대 승점을 계산하시오
// A는 A팀의 출전 순서
// B는 B팀의 번호목록

// A팀의 순서가 의미가 있나?
// 5 1 3 7
// 2 2 6 8 / 0,3
import java.util.*;
class Solution {
    boolean[]visit;
    int max=0;
    public int solution(int[] A, int[] B) {
        Arrays.sort(A);
        Arrays.sort(B);
        int a=0;
        int b=0;
        int result=0;
        for(int i=0;i<A.length;i++){
            if(A[a]>B[b]){
                b++;
            }else if(A[a]==B[b]){
                b++;
            }else{
                a++;
                b++;
                result++;
            }
        }
        return result;
    }
}
